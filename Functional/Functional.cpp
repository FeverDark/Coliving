// Functional.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "Functional.h"

const std::locale loc = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>);

Student::Student() {}
Student::~Student() {}
int Student::getRoom() {
	return this->room;
}
std::wstring Student::getName() {
	return this->name;
}
void Student::setRoom(int number) {
	this->room = number;
}
void Student::setName(std::wstring name) {
	this->name = name;
}
int Student::getType() {
	return this->type;
}
Student* Student::copy() {
	return NULL;
}

StudentFromSecond::StudentFromSecond(int room, std::wstring name) {
	this->room = room;
	this->name = name;
	this->type = 1;
}
StudentFromSecond::~StudentFromSecond() {}
StudentFromSecond::StudentFromSecond(const StudentFromSecond& temp) {
	this->room = temp.room;
	this->name = temp.name;
	this->type = temp.type;
}
Student* StudentFromSecond::copy() {
	return new StudentFromSecond(*this);
}

StudentFromThird::StudentFromThird(int room, std::wstring name) {
	this->room = room;
	this->name = name;
	this->type = 2;
}
StudentFromThird::~StudentFromThird() {}
StudentFromThird::StudentFromThird(const StudentFromThird& temp) {
	this->room = temp.room;
	this->name = temp.name;
	this->type = temp.type;
}
Student* StudentFromThird::copy() {
	return new StudentFromThird(*this);
}

StudentFromEight::StudentFromEight(int room, std::wstring name) {
	this->room = room;
	this->name = name;
	this->type = 3;
}
StudentFromEight::~StudentFromEight() {}
StudentFromEight::StudentFromEight(const StudentFromEight& temp) {
	this->room = temp.room;
	this->name = temp.name;
	this->type = temp.type;
}
Student* StudentFromEight::copy() {
	return new StudentFromEight(*this);
}

bool Comp::operator()(Student* s, double i) { return s->getType() < i; }
bool Comp::operator()(double i, Student* s) { return i < s->getType(); }

bool CompSet::operator() (Student* a, Student* b) const {
	return a->getRoom() < b->getRoom();
}

DB::DB() {
	second = new std::set<Student*, CompSet>;
	third = new std::set<Student*, CompSet>;
	eight = new std::set<Student*, CompSet>;
	int room;
	std::wstring str;
	std::wifstream file("second.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		room = NULL;
		file >> room >> str;
		str = regex_replace(str, std::wregex(L"_"), L" ");
		if (room != NULL)
			second->insert(new StudentFromSecond(room, str));
	}
	file.close();
	file = std::wifstream("third.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		room = NULL;
		file >> room >> str;
		str = regex_replace(str, std::wregex(L"_"), L" ");
		if (room != NULL)
			third->insert(new StudentFromThird(room, str));
	}
	file.close();
	file = std::wifstream("eight.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		room = NULL;
		file >> room >> str;
		str = regex_replace(str, std::wregex(L"_"), L" ");
		if (room != NULL)
			eight->insert(new StudentFromEight(room, str));
	}
	file.close();
};
DB::~DB() {
	saveFile();
	for (std::set<Student*, CompSet>::const_iterator it = second->begin(); it != second->end(); ++it) {
		delete *it;
	}
	for (std::set<Student*, CompSet>::const_iterator it = third->begin(); it != third->end(); ++it) {
		delete* it;
	}
	for (std::set<Student*, CompSet>::const_iterator it = eight->begin(); it != eight->end(); ++it) {
		delete* it;
	}
	delete second;
	delete third;
	delete eight;
}
DB::DB(const DB& temp) {
	second = new std::set<Student*, CompSet>;
	third = new std::set<Student*, CompSet>;
	eight = new std::set<Student*, CompSet>;
	for (std::set<Student*, CompSet>::const_iterator i = temp.second->begin(); i != temp.second->end(); ++i) {
		second->insert((*i)->copy());
	}
	for (std::set<Student*, CompSet>::const_iterator i = temp.third->begin(); i != temp.third->end(); ++i) {
		third->insert((*i)->copy());
	}
	for (std::set<Student*, CompSet>::const_iterator i = temp.eight->begin(); i != temp.eight->end(); ++i) {
		eight->insert((*i)->copy());
	}
};
DB& DB::operator=(const DB& temp) {
	if (this != &temp) {
		for (std::set<Student*, CompSet>::const_iterator it = second->begin(); it != second->end(); ++it) {
			delete* it;
		}
		for (std::set<Student*, CompSet>::const_iterator it = third->begin(); it != third->end(); ++it) {
			delete* it;
		}
		for (std::set<Student*, CompSet>::const_iterator it = eight->begin(); it != eight->end(); ++it) {
			delete* it;
		}
		second->clear();
		third->clear();
		eight->clear();
		delete second;
		delete third;
		delete eight;
		second = new std::set<Student*, CompSet>;
		third = new std::set<Student*, CompSet>;
		eight = new std::set<Student*, CompSet>;
		for (std::set<Student*, CompSet>::const_iterator i = temp.second->begin(); i != temp.second->end(); ++i) {
			second->insert((*i)->copy());
		}
		for (std::set<Student*, CompSet>::const_iterator i = temp.third->begin(); i != temp.third->end(); ++i) {
			third->insert((*i)->copy());
		}
		for (std::set<Student*, CompSet>::const_iterator i = temp.eight->begin(); i != temp.eight->end(); ++i) {
			eight->insert((*i)->copy());
		}
	}
	return *this;
};
void DB::saveFile() {
	std::wofstream file("second.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::set<Student*, CompSet>::iterator i = this->second->begin(); i != this->second->end() && file.is_open(); ++i) {
		file << (*i)->getRoom() << " " << regex_replace((*i)->getName(), std::wregex(L" "), L"_");
		file << std::endl;
	}
	file.close();
	file = std::wofstream("third.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::set<Student*, CompSet>::iterator i = this->third->begin(); i != this->third->end() && file.is_open(); ++i) {
		file << (*i)->getRoom() << " " << regex_replace((*i)->getName(), std::wregex(L" "), L"_");
		file << std::endl;
	}
	file.close();
	file = std::wofstream("eight.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::set<Student*, CompSet>::iterator i = this->eight->begin(); i != this->eight->end() && file.is_open(); ++i) {
		file << (*i)->getRoom() << " " << regex_replace((*i)->getName(), std::wregex(L" "), L"_");
		file << std::endl;
	}
	file.close();
}

CFunctional::CFunctional() {
	db = new DB();
}

CFunctional* CFunctional::getInstance() {
	if (!instance)
		instance = new CFunctional();
	return instance;
}
CFunctional::~CFunctional() {
	delete db;
};

CFunctional* CFunctional::instance = 0;

void CFunctional::getAllStudents(int& size, int* (&room), wchar_t** (&str), std::wstring filter, int number) {
	std::locale::global(std::locale(""));
	std::transform(filter.begin(), filter.end(), filter.begin(), towlower);
	std::set<Student*, CompSet> all;
	std::set_union(db->second->begin(), db->second->end(), db->third->begin(), db->third->end(), std::inserter(all, all.begin()));
	std::set_union(db->eight->begin(), db->eight->end(), all.begin(), all.end(), std::inserter(all, all.begin()));
	auto range = std::equal_range(all.begin(), all.end(), number, Comp{});
	if (number > 0) {
		//auto range = std::equal_range(all.begin(), all.end(), number, Comp{})
	}
	else {
		//auto range = std::equal_range(all.begin(), all.end(), number, Comp{})
	}
	size = db->second->size() + db->third->size() + db->eight->size();
	room = new int[size];
	str = new wchar_t* [size];
	int j = 0;
	for (auto i = range.first; i != range.second; ++i) {
		std::wstring tempname = (*i)->getName();
		std::wstring temproom = std::to_wstring((*i)->getRoom());
		transform(tempname.begin(), tempname.end(), tempname.begin(), towlower);
		if (filter == L"" || tempname.find(filter) != std::wstring::npos || temproom.find(filter) != std::wstring::npos) {
			room[j] = (*i)->getRoom();
			str[j] = new wchar_t[1024];
			wcscpy_s(str[j], 1024, (*i)->getName().c_str());
			j++;
		}
	}
	/*for (std::set<Student*, CompSet>::const_iterator i = db->third->begin(); i != db->third->end(); ++i) {
		std::wstring tempname = (*i)->getName();
		std::wstring temproom = std::to_wstring((*i)->getRoom());
		transform(tempname.begin(), tempname.end(), tempname.begin(), towlower);
		if (filter == L"" || tempname.find(filter) != std::wstring::npos || temproom.find(filter) != std::wstring::npos) {
			room[j] = (*i)->getRoom();
			str[j] = new wchar_t[1024];
			wcscpy_s(str[j], 1024, (*i)->getName().c_str());
			j++;
		}
	}
	for (std::set<Student*, CompSet>::const_iterator i = db->eight->begin(); i != db->eight->end(); ++i) {
		std::wstring tempname = (*i)->getName();
		std::wstring temproom = std::to_wstring((*i)->getRoom());
		transform(tempname.begin(), tempname.end(), tempname.begin(), towlower);
		if (filter == L"" || tempname.find(filter) != std::wstring::npos || temproom.find(filter) != std::wstring::npos) {
			room[j] = (*i)->getRoom();
			str[j] = new wchar_t[1024];
			wcscpy_s(str[j], 1024, (*i)->getName().c_str());
			j++;
		}
	}*/
	size = j;
}

void CFunctional::getStudentsFromSecond(int& size, int* (&room), wchar_t** (&str), std::wstring filter) {
	std::locale::global(std::locale(""));
	std::transform(filter.begin(), filter.end(), filter.begin(), towlower);
	size = db->second->size();
	room = new int[size];
	str = new wchar_t* [size];
	int j = 0;
	for (std::set<Student*, CompSet>::const_iterator i = db->second->begin(); i != db->second->end(); ++i) {
		std::wstring tempname = (*i)->getName();
		std::wstring temproom = std::to_wstring((*i)->getRoom());
		transform(tempname.begin(), tempname.end(), tempname.begin(), towlower);
		if (filter == L"" || tempname.find(filter) != std::wstring::npos || temproom.find(filter) != std::wstring::npos) {
			room[j] = (*i)->getRoom();
			str[j] = new wchar_t[1024];
			wcscpy_s(str[j], 1024, (*i)->getName().c_str());
			j++;
		}
	}
	size = j;
}

void CFunctional::getStudentsFromThird(int& size, int* (&room), wchar_t** (&str), std::wstring filter) {
	std::locale::global(std::locale(""));
	std::transform(filter.begin(), filter.end(), filter.begin(), towlower);
	size = db->third->size();
	room = new int[size];
	str = new wchar_t* [size];
	int j = 0;
	for (std::set<Student*, CompSet>::const_iterator i = db->third->begin(); i != db->third->end(); ++i) {
		std::wstring tempname = (*i)->getName();
		std::wstring temproom = std::to_wstring((*i)->getRoom());
		transform(tempname.begin(), tempname.end(), tempname.begin(), towlower);
		if (filter == L"" || tempname.find(filter) != std::wstring::npos || temproom.find(filter) != std::wstring::npos) {
			room[j] = (*i)->getRoom();
			str[j] = new wchar_t[1024];
			wcscpy_s(str[j], 1024, (*i)->getName().c_str());
			j++;
		}
	}
	size = j;
}

void CFunctional::getStudentsFromEight(int& size, int* (&room), wchar_t** (&str), std::wstring filter) {
	std::locale::global(std::locale(""));
	std::transform(filter.begin(), filter.end(), filter.begin(), towlower);
	size = db->eight->size();
	room = new int[size];
	str = new wchar_t* [size];
	int j = 0;
	for (std::set<Student*, CompSet>::const_iterator i = db->eight->begin(); i != db->eight->end(); ++i) {
		std::wstring tempname = (*i)->getName();
		std::wstring temproom = std::to_wstring((*i)->getRoom());
		transform(tempname.begin(), tempname.end(), tempname.begin(), towlower);
		if (filter == L"" || tempname.find(filter) != std::wstring::npos || temproom.find(filter) != std::wstring::npos) {
			room[j] = (*i)->getRoom();
			str[j] = new wchar_t[1024];
			wcscpy_s(str[j], 1024, (*i)->getName().c_str());
			j++;
		}
	}
	size = j;
}
