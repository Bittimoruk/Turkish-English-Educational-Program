// https://unixcheats.com/ - Bittimoruk - Turkish-English-Educational-Program - Türkçe-İngilizce Eğitici Program
#include <iostream>
#include <locale.h> //Tüm dillerin olduğu kütüphanemiz.
#include <fstream> //Dosya okuma ve yazdırma kütüphanemiz.
#include <string>
#include <conio.h> //_getch(); kullanabilmemiz için.
#include <windows.h>
#include <codecvt>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

typedef vector<uint32_t> lst;
typedef vector<wstring> vectorWordlist;

wstring convert(wstring a)
{
	for (int i1 = 0; i1 < a.length(); i1++)
	{
		a[i1] = toupper(a[i1]);
	}
	return a;
}

wstring convert2(wstring character)
{
	for (int i2 = 0; i2 < character.length(); i2++)
	{
		character[i2] = toupper(character[i2]);
	}
	return character;
}

int main() {
bb:
	SetConsoleOutputCP(1254);
	SetConsoleCP(1254);
	setlocale(LC_ALL, "Turkish"); //Türkçe kütüphanesini programa ekledik.

	vector<wstring> vectorWordlist; vector<uint32_t> lst;

	wstring character; wstring wordlistRandom; wstring words;

	int selectLanguage; int totalLinage = 0;

	wcout << L"Hangi dilde cevaplamak istiyorsun?" << endl << L"\n[TR] -> Türkçe\n" << L"[ING] -> İngilizce\n" << L"[1] -> Wordlist_wrong.txt'i Sil\n" << L"[2] -> Wordlist_wrong2.txt'i Sil\n" << endl;
	wcout << L"Komut : ";
	wcin >> character;
	if (character == L"TR" || character == L"Tr" || character == L"tr"
		|| character == L"TÜRKÇE" || character == L"Türkçe" || character == L"türkçe") {
		selectLanguage = 1;
	}
	else if (character == L"ING" || character == L"Ing" || character == L"ıng"
		|| character == L"İNG" || character == L"İng" || character == L"ing"
		|| character == L"İNGİLİZCE" || character == L"İngilizce"
		|| character == L"ingilizce" || character == L"INGİLİZCE"
		|| character == L"Ingilizce" || character == L"ıngilizce") {
		selectLanguage = 2;
	}
	else if (character == L"1") {
		remove("Wordlist_wrong.txt");
		system("cls");
		wcout << L"Wordlist_wrong.txt dosyası silindi. ";
		goto bb;
	}
	else if (character == L"2") {
		remove("Wordlist_wrong2.txt");
		system("cls");
		wcout << L"Wordlist_wrong2.txt dosyası silindi. ";
		goto bb;
	}
	else {
		system("cls");
		wcout << L"Hatalı seçim yaptın. Tekrar seçim yapmalısın. ";
		goto bb;
	}
	system("cls");

	wcout << L"Hangi harfi seçmek istiyorsun?" << endl << L"\n[ALL] -> Bütün alfabe\n" << endl;
	wcout << L"Komut : ";
	wcin >> character;

	const locale empty_locale = locale::empty();
	typedef codecvt_utf8<wchar_t> converter_type;
	const converter_type* converter = new converter_type;
	const locale utf8_locale = locale(empty_locale, converter);
	wifstream myfileRead(L"Wordlist_" + character + L".txt");
	wofstream myfileWrite;
	if (character == L"wrong") {
		myfileWrite.open(L"Wordlist_wrong2.txt");
	}
	else if (character == L"wrong2") {
		system("cls");
		wcout << L"Bu Dosyayı açamazsınız. ";
		goto bb;
	}
	else if (!myfileRead.is_open()) {
		system("cls");
		wcout << L"Dosya bulunamadı. ";
		goto bb;
	}
	else {
		myfileWrite.open(L"Wordlist_wrong.txt", ios::app);
	}

	myfileRead.imbue(utf8_locale);
	myfileWrite.imbue(utf8_locale);

	system("cls");
	wcout << L"Kelimelerin rastgele olarak sıralanmasını ister misin?\n" << endl << L"[Evet] -> Kelimeler rastgele olarak sıralanır" << endl << L"[Hayır] -> Kelimeler sıralı olarak sıralanır\n" << endl;
	wcin >> wordlistRandom;
	wcout << endl;

	if (wordlistRandom == L"EVET" || wordlistRandom == L"Evet" || wordlistRandom == L"evet") {
		if (myfileRead.is_open()) {
			while (getline(myfileRead, wordlistRandom)) {
				if (wordlistRandom.find(L"=")) {
					++totalLinage;
					//wcout << L"Toplam satır sayısı : " << totalLinage << endl;
					vectorWordlist.push_back(wordlistRandom);
				}
			}
		}

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<uint32_t> dist(1, totalLinage);
		while (lst.size() < totalLinage) {
			uint32_t r;
			do {
				r = dist(gen);
			} while (find(lst.begin(), lst.end(), r) != lst.end());
			lst.push_back(r);
		}

		myfileRead.close();
		wordlistRandom = L"yes";
	}
	else {
		if (myfileRead.is_open()) {
			while (getline(myfileRead, wordlistRandom)) {
				if (wordlistRandom.find(L"=")) {
					++totalLinage;
					//wcout << L"Toplam satır sayısı : " << totalLinage << endl;
					vectorWordlist.push_back(wordlistRandom);
				}
			}
		}

		myfileRead.close();
		wordlistRandom = L"no";
	}

	wstring line; wstring wordIng; wstring wordIng2; wstring wordIng3; wstring wordIng4; wstring wordTr; wstring wordTr2; wstring wordTr3; wstring a;

	int one; int two; int three; int four; int five; int six; int seven; int total = 0; int right = 0; int wrong = 0; int multipleIng = 0;

	if (selectLanguage == 1) {
		system("cls");
		while (total < totalLinage) {

			if (wordlistRandom == L"yes") {
				line = vectorWordlist[lst[total] - 1];
			}
			else if (wordlistRandom == L"no") {
				line = vectorWordlist[total];
			}

			++total;

			one = line.find(L"="); two = (line.rfind(L"=") + 1);
			three = line.find(L","); four = line.rfind(L","); five = (line.length() - 1);
			six = line.find(L"/"); seven = line.rfind(L"/");

			wordIng = line.substr(0, one);
			multipleIng = 0;
			if (six > 0) {
				multipleIng = 1;
				wordIng2 = line.substr(0, six);
				if (six != seven) {
					multipleIng = 3;
					wordIng3 = line.substr(six + 1, seven - six - 1);
					wordIng4 = line.substr(seven + 1, one - seven - 1);
				}
				else {
					multipleIng = 2;
					wordIng3 = line.substr(six + 1, one - six - 1);
				}
			}
			wordTr = line.substr(two, three - two);
			wordTr2 = line.substr(three + 1, four - three - 1);
			wordTr3 = line.substr(four + 1, five);
			if (six > 0) {
				if (six != seven) {
					wcout << L"\"" + wordIng2 << L", " + wordIng3 << L", " + wordIng4 << L"\"" << L" kelimesinin Türkçe anlamı nedir?\n" << endl;
				}
				else {
					wcout << L"\"" + wordIng2 << L", " + wordIng3 << L"\"" << L" kelimesinin Türkçe anlamı nedir?\n" << endl;
				}
			}
			else {
				wcout << L"\"" + wordIng << L"\"" << L" kelimesinin Türkçe anlamı nedir?\n" << endl;
			}
			wcout << L"Cevap : ";
			if (total <= 1) {
				getchar();
			}
			getline(wcin, a);
			if (convert(a) == convert(wordTr) || convert(a) == convert(wordTr2) || convert(a) == convert(wordTr3) || convert(a) == convert(wordTr) + L" " + convert(wordTr2) + L" " + convert(wordTr3) || convert(a) == convert(wordTr) + L" " + convert(wordTr2) || convert(a) == convert(wordTr) + L" " + convert(wordTr3) || convert(a) == convert(wordTr2) + L" " + convert(wordTr3)) {
				wcout << L"\nTebrikler! Doğru bildiniz." << endl;
				wcout << L"---------------------------------------------------------------" << endl;
				++right;
			}
			else {
				if (four > 0) {
					if (three != four) {
						wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordTr << L", " + wordTr2 << L", " + wordTr3 << L"\" olacaktı." << endl;
						if (six > 0) {
							if (six != seven) {
								myfileWrite << wordIng2 + L"/" << wordIng3 + L"/" << wordIng4 + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
							}
							else {
								myfileWrite << wordIng2 + L"/" << wordIng3 + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
							}
						}
						else {
							myfileWrite << wordIng + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
						}
					}
					else {
						wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordTr << L", " + wordTr2 << L"\" olacaktı." << endl;
						if (six > 0) {
							if (six != seven) {
								myfileWrite << wordIng2 + L"/" << wordIng3 + L"/" << wordIng4 + L"=" << wordTr + L"," << wordTr2 + L"\n";
							}
							else {
								myfileWrite << wordIng2 + L"/" << wordIng3 + L"=" << wordTr + L"," << wordTr2 + L"\n";
							}
						}
						else {
							myfileWrite << wordIng + L"=" << wordTr + L"," << wordTr2 + L"\n";
						}
					}
				}
				else {
					wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordTr << L"\" olacaktı." << endl;
					if (six > 0) {
						if (six != seven) {
							myfileWrite << wordIng2 + L"/" << wordIng3 + L"/" << wordIng4 + L"=" << wordTr + L"\n";
						}
						else {
							myfileWrite << wordIng2 + L"/" << wordIng3 + L"=" << wordTr + L"\n";
						}
					}
					else {
						myfileWrite << wordIng + L"=" << wordTr + L"\n";
					}
				}
				wcout << L"---------------------------------------------------------------" << endl;
				++wrong;
			}
		}
	}
	if (selectLanguage == 2) {
		system("cls");
		while (total < totalLinage) {

			if (wordlistRandom == L"yes") {
				line = vectorWordlist[lst[total] - 1];
			}
			else if (wordlistRandom == L"no") {
				line = vectorWordlist[total];
			}

			++total;
			one = line.find(L"="); two = (line.rfind(L"=") + 1);
			three = line.find(L","); four = line.rfind(L","); five = (line.length() - 1);
			six = line.find(L"/"); seven = line.rfind(L"/");

			wordIng = line.substr(0, one);
			multipleIng = 0;
			if (six > 0) {
				multipleIng = 1;
				wordIng2 = line.substr(0, six);
				if (six != seven) {
					multipleIng = 3;
					wordIng3 = line.substr(six + 1, seven - six - 1);
					wordIng4 = line.substr(seven + 1, one - seven - 1);
				}
				else {
					multipleIng = 2;
					wordIng3 = line.substr(six + 1, one - six - 1);
				}
			}
			wordTr = line.substr(two, three - two);
			wordTr2 = line.substr(three + 1, four - three - 1);
			wordTr3 = line.substr(four + 1, five);
			if (four > 0) {
				if (three != four) {
					wcout << L"\"" + wordTr << L", " + wordTr2 << L", " + wordTr3 << L"\"" << L" kelimesinin İngilizce yazılışı nedir?\n" << endl;
				}
				else {
					wcout << L"\"" + wordTr << L", " + wordTr2 << L"\"" << L" kelimesinin İngilizce yazılışı nedir?\n" << endl;
				}
			}
			else {
				wcout << L"\"" + wordTr << L"\"" << L" kelimesinin İngilizce yazılışı nedir?\n" << endl;
			}
			wcout << L"Cevap : ";
			if (total <= 1) {
				getchar();
			}
			getline(wcin, a);
			if (convert(a) == convert(wordIng)) {
				wcout << L"\nTebrikler! Doğru bildiniz." << endl;
				wcout << L"---------------------------------------------------------------" << endl;
				++right;
			}
			else if (convert(a) == convert(wordIng2) || convert(a) == convert(wordIng3)) {
				wcout << L"\nTebrikler! Doğru bildiniz." << endl;
				wcout << L"---------------------------------------------------------------" << endl;
				++right;
			}
			else if (convert(a) == convert(wordIng2) || convert(a) == convert(wordIng3) || convert(a) == convert(wordIng4)) {
				wcout << L"\nTebrikler! Doğru bildiniz." << endl;
				wcout << L"---------------------------------------------------------------" << endl;
				++right;
			}
			else {
				if (multipleIng == 3) {
					wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordIng2 << L", " + wordIng3 << L", " + wordIng4 << L"\" olacaktı." << endl;
					if (four > 0) {
						if (three != four) {
							myfileWrite << wordIng2 + L"/" << wordIng3 + L"/" << wordIng4 + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
						}
						else {
							myfileWrite << wordIng2 + L"/" << wordIng3 + L"/" << wordIng4 + L"=" << wordTr + L"," << wordTr2 + L"\n";
						}
					}
					else {
						myfileWrite << wordIng2 + L"/" << wordIng3 + L"/" << wordIng4 + L"=" << wordTr + L"\n";
					}
				}
				else if (multipleIng == 2) {
					wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordIng2 << L", " + wordIng3 << L"\" olacaktı." << endl;
					if (four > 0) {
						if (three != four) {
							myfileWrite << wordIng2 + L"/" << wordIng3 + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
						}
						else {
							myfileWrite << wordIng2 + L"/" << wordIng3 + L"=" << wordTr + L"," << wordTr2 + L"\n";
						}
					}
					else {
						myfileWrite << wordIng2 + L"/" << wordIng3 + L"=" << wordTr + L"\n";
					}
				}
				else if (multipleIng == 1) {
					wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordIng2 << L"\" olacaktı." << endl;
					if (four > 0) {
						if (three != four) {
							myfileWrite << wordIng2 + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
						}
						else {
							myfileWrite << wordIng2 + L"=" << wordTr + L"," << wordTr2 + L"\n";
						}
					}
					else {
						myfileWrite << wordIng2 + L"=" << wordTr + L"\n";
					}
				}
				else if (multipleIng == 0) {
					wcout << L"\nAh! Yanlış girdin. " << L"Doğru cevap : \"" + wordIng << L"\" olacaktı." << endl;
					if (four > 0) {
						if (three != four) {
							myfileWrite << wordIng + L"=" << wordTr + L"," << wordTr2 + L"," << wordTr3 + L"\n";
						}
						else {
							myfileWrite << wordIng + L"=" << wordTr + L"," << wordTr2 + L"\n";
						}
					}
					else {
						myfileWrite << wordIng + L"=" << wordTr + L"\n";
					}
				}
				wcout << L"---------------------------------------------------------------" << endl;
				++wrong;
			}
		}
	}

	myfileWrite.close();
	int success = (right * 100) / total;
	wcout << L"\nToplam doğru cevabınız : " << right << L" | " << L"Toplam yanlış cevabınız : " << wrong << L" | " << L"Başarı durumu : %" << success << endl;
	wcout << L"\n---------------------------------------------------------------\n" << endl;
	wcout << L"Tebrikler! Programdan çıkmak için herhangi bir tuşa basabilirsiniz." << endl;
	_getch();
	return 0;
}
