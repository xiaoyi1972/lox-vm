#pragma once
#include "token.h"
#include<array>
namespace  Lox{
	enum struct Precedence {
		NONE,
		ASSIGNMENT,  // =
		OR,          // or
		AND,         // and
		EQUALITY,    // == !=
		COMPARISON,  // < > <= >=
		TERM,        // + -
		FACTOR,      // * /
		UNARY,       // ! -
		CALL,        // . ()
		PRIMARY
	};

	template<class T>
	struct ParseRule {
		using ParseFn = void (T::*)(bool);
		ParseFn prefix;
		ParseFn infix;
		Precedence precedence;
	};

	template<TokenType type, class T> struct EnumForType;
	template<class T> struct EnumForType<TokenType::left_paren, T> {
		static constexpr ParseRule<T> value{ &T::grouping,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::right_paren, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::left_brace, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::right_brace, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::comma, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::dot, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::minus, T> {
		static constexpr ParseRule<T> value{ &T::unary,&T::binary,Precedence::TERM };
	};
	template<class T> struct EnumForType<TokenType::plus, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::TERM };
	};
	template<class T> struct EnumForType<TokenType::semicolon, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::slash, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::FACTOR };
	};
	template<class T> struct EnumForType<TokenType::star, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::FACTOR };
	};
	template<class T> struct EnumForType<TokenType::bang, T> {
		static constexpr ParseRule<T> value{ &T::unary,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::bang_equal, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::EQUALITY };
	};
	template<class T> struct EnumForType<TokenType::equal, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::equal_equal, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::EQUALITY };
	};
	template<class T> struct EnumForType<TokenType::greater, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::EQUALITY };
	};
	template<class T> struct EnumForType<TokenType::greater_equal, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::EQUALITY };
	};
	template<class T> struct EnumForType<TokenType::less, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::EQUALITY };
	};
	template<class T> struct EnumForType<TokenType::less_equal, T> {
		static constexpr ParseRule<T> value{ nullptr,&T::binary,Precedence::EQUALITY };
	};
	template<class T> struct EnumForType<TokenType::identifier, T> {
		static constexpr ParseRule<T> value{ &T::variable,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::string, T> {
		static constexpr ParseRule<T> value{ &T::string,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::number, T> {
		static constexpr ParseRule<T> value{ &T::number,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_and, T> {
		static constexpr ParseRule<T> value{ nullptr, &T::and_,Precedence::AND };
	};
	template<class T> struct EnumForType<TokenType::kw_class, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_else, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_false, T> {
		static constexpr ParseRule<T> value{ &T::literal,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_for, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::fun, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_if, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::nil, T> {
		static constexpr ParseRule<T> value{ &T::literal,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_or, T> {
		static constexpr ParseRule<T> value{ nullptr, &T::or_,Precedence::OR };
	};
	template<class T> struct EnumForType<TokenType::print, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_return, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::super, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_this, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_true, T> {
		static constexpr ParseRule<T> value{ &T::literal,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::var, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_while, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::error, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::eof, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::elif, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_continue, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T> struct EnumForType<TokenType::kw_break, T> {
		static constexpr ParseRule<T> value{ nullptr,nullptr,Precedence::NONE };
	};
	template<class T, std::size_t...Is>
	std::array<ParseRule<T>, sizeof...(Is)> ParseRuleHelp(std::index_sequence<Is...> const&)
	{
		return { EnumForType<static_cast<TokenType>(Is),T>::value... };
	}
}