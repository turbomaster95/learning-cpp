#include <iostream>
#include <stack>

#define print(text) cout << text << endl

struct student {
	std::string name;
	int age;
	char grade;
};

int main() {
	using namespace std;

	string intro = "Hello, World!";
	print(intro);

	string name;
	
	print("give me ur name:");
	getline(cin, name);
	print("Hello, " + name);

	for (char let : name) print(let);

	student stud1;
	stud1.name = "Liam";
	stud1.age = 35;
	stud1.grade = 'A';

  print("Student name: " << stud1.name);
  print("Student age: " << stud1.age);
  print("Student grade: " << stud1.grade);

	student &man = stud1; // makes a full on reference to stud1

  print("Man name: " + man.name);

	auto msg = [](){ print("h"); };

	msg();

	stack<string> stk;

	stk.push("game");
	stk.push("game1");

	cout << stk.top() << endl;
	return 0;
}
