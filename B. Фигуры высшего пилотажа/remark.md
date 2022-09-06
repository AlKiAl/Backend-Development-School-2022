https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/

https://ru.stackoverflow.com/questions/741306/%D0%9A%D0%B0%D0%BA-%D1%80%D0%B0%D0%B7%D0%B1%D0%B8%D1%82%D1%8C-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D1%83-%D0%BF%D0%BE-%D0%B7%D0%B0%D0%BF%D1%8F%D1%82%D0%BE%D0%B9-%D0%BA%D1%80%D0%BE%D0%BC%D0%B5-%D1%81%D0%BB%D1%83%D1%87%D0%B0%D1%8F-%D0%BA%D0%BE%D0%B3%D0%B4%D0%B0-%D0%B7%D0%B0-%D0%BD%D0%B5%D0%B9-%D1%81%D0%BB%D0%B5%D0%B4%D1%83%D0%B5%D1%82-%D0%BF%D1%80%D0%BE%D0%B1%D0%B5%D0%BB 



First name Last name, [9/6/2022 7:53 PM]
друзья, положим, есть такой кусок кода:
...
struct Person{
  string ID;
  int x= 0;
  int y = 0;
};
...
unordered_map <string, vector<Person>>s_i_to_Person;
...

Я могу как-то отсортировать то, что будет содержаться в vector<Person>?

Anatoly Shirokov, [9/6/2022 7:54 PM]
[In reply to First name Last name]
Конечно, путем вызова std::sort и определением предиката меньше для пары двух Person или определите operator<, тогда можно дефолтный std::less
