#pragma once

#include <ostream>
#include <utility>
//#include <ciso646>
#include <string>
#include <string_view>

namespace bibliotheque_cours {

bool initialiserGoogleTest(int& argc, char** argv);
int executerGoogleTest(int& argc, char** argv, bool seulementSiArguments = false, bool arreterSiErreur = false);

// dbgbuf et dbgstream sont bas�s sur un code par Dietmar Kuehl post� ici https://www.flipcode.com/archives/Debug_Stream.shtml

class dbgbuf : public std::streambuf {
public:
	dbgbuf(const dbgbuf&) = delete;             // Not copy constructible.
	dbgbuf& operator= (const dbgbuf&) = delete; // Not copyable.
	dbgbuf(dbgbuf &&) = default;                // Move construtible.
	dbgbuf& operator= (dbgbuf&&) = default;     // Movable.

	dbgbuf() : teeOutput(nullptr) { };

	~dbgbuf() { flushMessageBuffer(); }

	/// Set a stream to be used as an additional output.  Messages are directed to this stream as well as to "debug" output.  Returns the previous tee.
	std::ostream* setTee(std::ostream* tee_) {
		std::swap(teeOutput, tee_);
		return tee_;
	}

	/// Returns current tee.
	std::ostream* getTee() { return teeOutput; }

protected:
	/// streambuf implementation. 
	virtual int_type overflow(int_type ch) {
		if (ch == traits_type::eof())
			return traits_type::eof();

		logMessageBuffer += traits_type::to_char_type(ch);
		if (ch == '\n')
			sync();
		return not traits_type::eof();
	}
	virtual int sync() { flushMessageBuffer(); return 0; }

private:
	void flushMessageBuffer();

	std::string   logMessageBuffer;
	std::ostream* teeOutput;
};

class dbgstream : public std::ostream
{
public:
	explicit dbgstream() : std::ostream(nullptr) { init(&debugStreamBuf); }

	/// Set a stream to be used as an additional output.  Messages are directed to this stream as well as to "debug" output.  Returns the previous tee.
	std::ostream *setTee(std::ostream* tee_) {
		return debugStreamBuf.setTee(tee_);
	}
	
	/// Returns current tee.
	std::ostream* getTee() { return debugStreamBuf.getTee(); }

private:
	dbgbuf debugStreamBuf;
};

extern dbgstream cdbg;

// Classe pour activer l'utilisation de la console en UTF-8 ou l'encodage standard de l'environnement (g�n�ralement Latin-1 dans Visual Studio).
// Pour l'UTF-8 dans Visual Studio, le projet doit avoir l'"option suppl�mentaire": /execution-charset:utf-8
// Attention qu'en UTF-8 les caract�res accentu�s prennent plus d'un char, on ne peut donc pas �crire '�' mais "�" est une chaine valide de 2 char ("�" est encod� comme les deux octets/chars C3 A9).
// La classe doit �tre instanci�e avant d'utiliser cin en UTF-8, similairement � ios_base::Init.  Elle est instanci�e dans l'ent�te, donc vous n'avez pas � vous en occuper si vous incluez cet ent�te.
class InitConsole { public: InitConsole(); };
static inline InitConsole _initConsole;  // Une instance pour l'initialiser.

static constexpr bool executionEstUtf8 = sizeof("�") == 3 and "�"[0] == char(0xC3U) and "�"[1] == char(0xA9U);  //NOTE: Certaines version de gcc donnent l'erreur "error: converting to execution character set: Invalid argument" si ce fichier n'est pas en UTF-8 et qu'on tente d'avoir une encodage d'ex�cution en latin-1.

void activerCouleursAnsi();

}
