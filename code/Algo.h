#pragma once

#include <string>

inline int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

inline int findCoprime(int n) {
	for (int i = 2; i < n; i++) {
		if (gcd(n, i) == 1) {
			return i;
		}
	}
	return -1;
}

inline bool isNumeric(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

inline System::Boolean IsValidFIO(System::String^ text) {
	if (text == nullptr || text->Length == 0)
		return false;

	int spaceCount = 0;
	bool allWordsAreValid = true;

	for (int i = 0; i < text->Length; i++)
	{
		if (System::Char::IsWhiteSpace(text[i]))
		{
			spaceCount++;
			if (i + 1 < text->Length && !System::Char::IsUpper(text[i + 1]))
			{
				allWordsAreValid = false;
				break;
			}
			while (i + 1 < text->Length && System::Char::IsWhiteSpace(text[i + 1]))
			{
				i++;
			}
		}
		else if (i == 0 && !System::Char::IsUpper(text[i]))
		{
			allWordsAreValid = false;
			break;
		}
		else if (!System::Char::IsLetter(text[i]))
		{
			allWordsAreValid = false;
			break;
		}
	}

	if (spaceCount == 2 && allWordsAreValid)
	{
		return true;
	}
	System::Windows::Forms::MessageBox::Show("Пожалуйста, введите корректное ФИО, где каждое слово начинается с заглавной буквы, и слова разделены пробелами.", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	return false;
}

inline System::Boolean IsValidYear(System::String^ text) {
	if (text == nullptr || text->Length == 0)
		return false;

	int year;
	if (System::Int32::TryParse(text, year))
	{
		if (year >= 0 && year <= 2023)
		{
			return true;
		}
	}

	return false;
}

inline System::Boolean IsValidBookTitle(System::String^ text) {
	if (text == nullptr || text->Length == 0)
		return false;
	bool firstCharIsUpperOrDigit = System::Char::IsUpper(text[0]) || System::Char::IsDigit(text[0]);
	bool allCharsAreAlphaNumeric = true;
	for (int i = 1; i < text->Length; i++)
	{
		if (!System::Char::IsLetterOrDigit(text[i]) && !System::Char::IsWhiteSpace(text[i]))
		{
			allCharsAreAlphaNumeric = false;
			break;
		}
	}
	if (firstCharIsUpperOrDigit && allCharsAreAlphaNumeric)
	{
		return true;
	}

	System::Windows::Forms::MessageBox::Show("Пожалуйста, введите корректное название книги с первой заглавной буквой (или цифрой) и буквами английского алфавита, разделенное пробелом.", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	return false;
}

inline System::Boolean IsValidGenre(System::String^ text) {
	if (text == nullptr || text->Length == 0)
		return false;
	bool firstCharIsUpper = System::Char::IsUpper(text[0]);
	bool allOtherCharsAreLower = true;
	for (int i = 1; i < text->Length; i++)
	{
		if (!System::Char::IsLower(text[i]))
		{
			if (text[i] != ' ') {
				allOtherCharsAreLower = false;
				break;
			}
		}
	}
	if (firstCharIsUpper && allOtherCharsAreLower)
	{
		return true;
	}

	System::Windows::Forms::MessageBox::Show("Пожалуйста, введите корректный жанр с первой заглавной буквой и буквами английского алфавита, разделенный одним пробелом.", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	return false;
}