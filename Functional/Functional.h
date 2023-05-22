// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа FUNCTIONAL_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции FUNCTIONAL_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef FUNCTIONAL_EXPORTS
#define FUNCTIONAL_API __declspec(dllexport)
#else
#define FUNCTIONAL_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <clocale>
#include <cwctype>
#include <codecvt>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <regex>
#include <algorithm>

class Student {
protected:
	int room;
	std::wstring name;
	int type = 0;
public:
	Student();
	virtual ~Student();
	virtual int getRoom();
	virtual std::wstring getName();
	virtual void setRoom(int number);
	virtual void setName(std::wstring name);
	virtual int getType();
	virtual Student* copy();
};

class StudentFromSecond : public Student {
private:
public:
	StudentFromSecond(int room, std::wstring name);
	~StudentFromSecond();
	StudentFromSecond(const StudentFromSecond& temp);
	Student* copy();
};

class StudentFromThird : public Student {
private:
public:
	StudentFromThird(int room, std::wstring name);
	~StudentFromThird();
	StudentFromThird(const StudentFromThird& temp);
	Student* copy();
};

class StudentFromEight : public Student {
private:
public:
	StudentFromEight(int room, std::wstring name);
	~StudentFromEight();
	StudentFromEight(const StudentFromEight& temp);
	Student* copy();
};

struct Comp
{
	bool operator()(Student* s, double i);
	bool operator()(double i, Student* s);
};

struct FUNCTIONAL_API CompSet {
	bool operator() (Student* a, Student* b) const;
};

class DB {
public:
	std::set<Student*, CompSet>* second;
	std::set<Student*, CompSet>* third;
	std::set<Student*, CompSet>* eight;
	DB();
	~DB();
	DB(const DB& temp);
	DB& operator=(const DB& temp);
	void saveFile();
};

class FUNCTIONAL_API CFunctional {
private:
	static CFunctional* instance;
	CFunctional();
	CFunctional(const CFunctional&);
	CFunctional& operator=(CFunctional&);
public:
	static CFunctional* getInstance();
	~CFunctional();
	DB* db;
	void getAllStudents(int& size,int* (&room), wchar_t** (&str), std::wstring filter, int number);
	void getStudentsFromSecond(int& size, int* (&room), wchar_t** (&str), std::wstring filter);
	void getStudentsFromThird(int& size, int* (&room), wchar_t** (&str), std::wstring filter);
	void getStudentsFromEight(int& size, int* (&room), wchar_t** (&str), std::wstring filter);
};