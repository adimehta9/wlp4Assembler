#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* DFA STUFF

.STATES
start
i in int!
w wa wai wain!
i if!
e el els else!
w wh whi whil while!
p pr pri prin print printl println!
r re ret retu retur return!
N NU NUL NULL!
n ne new!
d de del dele delet delete!
id!
num!
lparen!
rparen!
lbrace!
rbrace!
become!
eq!
ex
nne!
lt!
gt!
le!
ge!
plus!
minus!
star!
slash!
pct!
comma!
semi!
lbrack!
rbrack!
amp!

.TRANSITIONS
start i i
i n in
i f if
i a-e g-m o-z A-Z 0-9 id
in t int
in a-s u-z A-Z 0-9 id
if a-z A-Z 0-9 id
int a-z A-Z 0-9 id
id A-Z a-z 0-9 id

start w w
w a wa
w h wh
w b-g i-z A-Z 0-9 id
wa i wai
wa a-h j-z A-Z 0-9 id
wh i whi
wh a-h j-z A-Z 0-9 id
wai n wain
wai a-m o-z A-Z 0-9 id
wain a-z A-Z 0-9 id
whi l whil
whi a-k m-z A-Z 0-9 id
whil e while
whil a-d f-z A-Z 0-9 id
while a-z A-Z 0-9 id

start e e
e l el
e a-d f-z A-Z 0-9 id
el s els
el a-r t-z A-Z 0-9 id
els e else
els a-d f-z A-Z 0-9 id
else a-z A-Z 0-9 id

start p p
p r pr
p a-q s-z A-Z 0-9 id
pr i pri
pr a-h j-z A-Z 0-9 id
pri n prin
pri a-m o-z A-Z 0-9 id
prin t print
prin a-s u-z A-Z 0-9 id
print l printl
print a-k m-z A-Z 0-9 id
printl n println
printl a-m o-z A-Z 0-9 id
println a-z A-Z 0-9 id

start r r
r e re
r a-d f-z A-Z 0-9 id
re t ret
re a-s u-z A-Z 0-9 id
ret u retu
ret a-t v-z A-Z 0-9 id
retu r retur
retu a-q s-z A-Z 0-9 id
retur n return
retur a-m o-z A-Z 0-9 id
return a-z A-Z 0-9 id

start N N
N U NU
N A-T V-Z a-z 0-9 id
NU L NUL
NU A-K M-Z a-z 0-9 id
NUL L NULL
NUL A-K M-Z a-z 0-9 id
NULL a-z A-Z 0-9 id

start n n
n e ne
n a-d f-z A-Z 0-9 id
ne w new
ne a-v x-z A-Z 0-9 id
new a-z A-Z 0-9 id

start d d
d e de
d a-d f-z A-Z 0-9 id
de l del
de a-k m-z A-Z 0-9 id
del e dele
del a-d f-z A-Z 0-9 id
dele t delet
dele a-s u-z A-Z 0-9 id
delet e delete
delet a-d f-z A-Z 0-9 id
delete a-z A-Z 0-9 id

start a-c f-h j-m o q s-v x-z A-L O-Z id

start 1-9 num
num 0-9 num

start ( lparen
start ) rparen
start { lbrace
start } rbrace
start [ lbrack
start ] rbrack

start = become
become = eq
start ! ex
ex = ne
start < lt
lt = le
start > gt
gt = ge
start + plus
start - minus
start * star
start / slash
start % pct
start , comma
start ; semi
start & amp



*/

class State {
  string name;
  bool accepting;
  string TOKEN;

public:
  map<char, State *> transitions;
  bool get_accepting() { return this->accepting; }
  string get_token() { return this->TOKEN; }
  State(string name, bool accepting, string token)
      : name{name}, accepting{accepting}, TOKEN{token} {}
};

int main() {

  string w;
  string s;
  vector<char> alphabets;
  map<string, State *> all_states;
  string start_name = "start";

  // ALPHABETS
  for (char c = 'a'; c <= 'z'; c++) {
    alphabets.push_back(c);
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    alphabets.push_back(c);
  }
  for (char c = '0'; c <= '9'; c++) {
    alphabets.push_back(c);
  }
  alphabets.push_back('(');
  alphabets.push_back(')');
  alphabets.push_back('{');
  alphabets.push_back('}');
  alphabets.push_back('=');
  alphabets.push_back('!');
  alphabets.push_back('<');
  alphabets.push_back('>');
  alphabets.push_back('+');
  alphabets.push_back('-');
  alphabets.push_back('*');
  alphabets.push_back('/');
  alphabets.push_back('%');
  alphabets.push_back(',');
  alphabets.push_back(';');
  alphabets.push_back('[');
  alphabets.push_back(']');
  alphabets.push_back('&');

  // STATES
  State *s1 = new State("start", false, "");
  all_states.emplace("start", s1);
  s1 = new State("zero", true, "NUM");
  all_states.emplace("zero", s1);
  s1 = new State("i", true, "ID");
  all_states.emplace("i", s1);
  s1 = new State("in", true, "ID");
  all_states.emplace("in", s1);
  s1 = new State("int", true, "INT");
  all_states.emplace("int", s1);
  s1 = new State("w", true, "ID");
  all_states.emplace("w", s1);
  s1 = new State("wa", true, "ID");
  all_states.emplace("wa", s1);
  s1 = new State("wai", true, "ID");
  all_states.emplace("wai", s1);
  s1 = new State("wain", true, "WAIN");
  all_states.emplace("wain", s1);
  s1 = new State("if", true, "IF");
  all_states.emplace("if", s1);
  s1 = new State("e", true, "ID");
  all_states.emplace("e", s1);
  s1 = new State("el", true, "ID");
  all_states.emplace("el", s1);
  s1 = new State("els", true, "ID");
  all_states.emplace("els", s1);
  s1 = new State("else", true, "ELSE");
  all_states.emplace("else", s1);
  s1 = new State("wh", true, "ID");
  all_states.emplace("wh", s1);
  s1 = new State("whi", true, "ID");
  all_states.emplace("whi", s1);
  s1 = new State("whil", true, "ID");
  all_states.emplace("whil", s1);
  s1 = new State("while", true, "WHILE");
  all_states.emplace("while", s1);
  s1 = new State("p", true, "ID");
  all_states.emplace("p", s1);
  s1 = new State("pr", true, "ID");
  all_states.emplace("pr", s1);
  s1 = new State("pri", true, "ID");
  all_states.emplace("pri", s1);
  s1 = new State("prin", true, "ID");
  all_states.emplace("prin", s1);
  s1 = new State("print", true, "ID");
  all_states.emplace("print", s1);
  s1 = new State("printl", true, "ID");
  all_states.emplace("printl", s1);
  s1 = new State("println", true, "PRINTLN");
  all_states.emplace("println", s1);
  s1 = new State("r", true, "ID");
  all_states.emplace("r", s1);
  s1 = new State("re", true, "ID");
  all_states.emplace("re", s1);
  s1 = new State("ret", true, "ID");
  all_states.emplace("ret", s1);
  s1 = new State("retu", true, "ID");
  all_states.emplace("retu", s1);
  s1 = new State("retur", true, "ID");
  all_states.emplace("retur", s1);
  s1 = new State("return", true, "RETURN");
  all_states.emplace("return", s1);
  s1 = new State("N", true, "ID");
  all_states.emplace("N", s1);
  s1 = new State("NU", true, "ID");
  all_states.emplace("NU", s1);
  s1 = new State("NUL", true, "ID");
  all_states.emplace("NUL", s1);
  s1 = new State("NULL", true, "NULL");
  all_states.emplace("NULL", s1);
  s1 = new State("n", true, "ID");
  all_states.emplace("n", s1);
  s1 = new State("ne", true, "ID");
  all_states.emplace("ne", s1);
  s1 = new State("new", true, "NEW");
  all_states.emplace("new", s1);
  s1 = new State("d", true, "ID");
  all_states.emplace("d", s1);
  s1 = new State("de", true, "ID");
  all_states.emplace("de", s1);
  s1 = new State("del", true, "ID");
  all_states.emplace("del", s1);
  s1 = new State("dele", true, "ID");
  all_states.emplace("dele", s1);
  s1 = new State("delet", true, "ID");
  all_states.emplace("delet", s1);
  s1 = new State("delete", true, "DELETE");
  all_states.emplace("delete", s1);
  s1 = new State("id", true, "ID");
  all_states.emplace("id", s1);
  s1 = new State("num", true, "NUM");
  all_states.emplace("num", s1);
  s1 = new State("lparen", true, "LPAREN");
  all_states.emplace("lparen", s1);
  s1 = new State("rparen", true, "RPAREN");
  all_states.emplace("rparen", s1);
  s1 = new State("lbrace", true, "LBRACE");
  all_states.emplace("lbrace", s1);
  s1 = new State("rbrace", true, "RBRACE");
  all_states.emplace("rbrace", s1);
  s1 = new State("become", true, "BECOMES");
  all_states.emplace("become", s1);
  s1 = new State("eq", true, "EQ");
  all_states.emplace("eq", s1);
  s1 = new State("ex", false, "");
  all_states.emplace("ex", s1);
  s1 = new State("nne", true, "NE");
  all_states.emplace("nne", s1);
  s1 = new State("lt", true, "LT");
  all_states.emplace("lt", s1);
  s1 = new State("gt", true, "GT");
  all_states.emplace("gt", s1);
  s1 = new State("le", true, "LE");
  all_states.emplace("le", s1);
  s1 = new State("ge", true, "GE");
  all_states.emplace("ge", s1);
  s1 = new State("plus", true, "PLUS");
  all_states.emplace("plus", s1);
  s1 = new State("minus", true, "MINUS");
  all_states.emplace("minus", s1);
  s1 = new State("star", true, "STAR");
  all_states.emplace("star", s1);
  s1 = new State("slash", true, "SLASH");
  all_states.emplace("slash", s1);
  s1 = new State("pct", true, "PCT");
  all_states.emplace("pct", s1);
  s1 = new State("comma", true, "COMMA");
  all_states.emplace("comma", s1);
  s1 = new State("semi", true, "SEMI");
  all_states.emplace("semi", s1);
  s1 = new State("lbrack", true, "LBRACK");
  all_states.emplace("lbrack", s1);
  s1 = new State("rbrack", true, "RBRACK");
  all_states.emplace("rbrack", s1);
  s1 = new State("amp", true, "AMP");
  all_states.emplace("amp", s1);

  State *from = all_states["start"];
  from->transitions.emplace('i', all_states["i"]);
  from = all_states["start"];
  from->transitions.emplace('0', all_states["zero"]);
  from = all_states["i"];
  from->transitions.emplace('n', all_states["in"]);
  from = all_states["i"];
  from->transitions.emplace('f', all_states["if"]);
  from = all_states["in"];
  from->transitions.emplace('t', all_states["int"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'f' || c == 'n')) {
      from = all_states["i"];
      from->transitions.emplace(c, all_states["id"]);
    }

    if (!(c == 't')) {
      from = all_states["in"];
      from->transitions.emplace(c, all_states["id"]);
    }

    from = all_states["if"];
    from->transitions.emplace(c, all_states["id"]);

    from = all_states["int"];
    from->transitions.emplace(c, all_states["id"]);

    from = all_states["id"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["i"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["in"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["if"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["int"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["id"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["i"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["in"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["if"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["int"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["id"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('w', all_states["w"]);
  from = all_states["w"];
  from->transitions.emplace('a', all_states["wa"]);
  from = all_states["w"];
  from->transitions.emplace('h', all_states["wh"]);
  from = all_states["wa"];
  from->transitions.emplace('i', all_states["wai"]);
  from = all_states["wh"];
  from->transitions.emplace('i', all_states["whi"]);
  from = all_states["wai"];
  from->transitions.emplace('n', all_states["wain"]);
  from = all_states["whi"];
  from->transitions.emplace('l', all_states["whil"]);
  from = all_states["whil"];
  from->transitions.emplace('e', all_states["while"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'a' || c == 'h')) {
      from = all_states["w"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'i')) {
      from = all_states["wa"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'i')) {
      from = all_states["wh"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'n')) {
      from = all_states["wai"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["wain"];
    from->transitions.emplace(c, all_states["id"]);
    if (!(c == 'l')) {
      from = all_states["whi"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'e')) {
      from = all_states["whil"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["while"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["w"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wa"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wh"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wai"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wain"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["whi"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["whil"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["while"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["w"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wa"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wh"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wai"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["wain"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["whi"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["whil"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["while"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('e', all_states["e"]);
  from = all_states["e"];
  from->transitions.emplace('l', all_states["el"]);
  from = all_states["el"];
  from->transitions.emplace('s', all_states["els"]);
  from = all_states["els"];
  from->transitions.emplace('e', all_states["else"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'l')) {
      from = all_states["e"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 's')) {
      from = all_states["e"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'e')) {
      from = all_states["els"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["else"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["e"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["e"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["els"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["else"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["e"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["e"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["els"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["else"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('p', all_states["p"]);
  from = all_states["p"];
  from->transitions.emplace('r', all_states["pr"]);
  from = all_states["pr"];
  from->transitions.emplace('i', all_states["pri"]);
  from = all_states["pri"];
  from->transitions.emplace('n', all_states["prin"]);
  from = all_states["prin"];
  from->transitions.emplace('t', all_states["print"]);
  from = all_states["print"];
  from->transitions.emplace('l', all_states["printl"]);
  from = all_states["printl"];
  from->transitions.emplace('n', all_states["println"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'r')) {
      from = all_states["p"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'i')) {
      from = all_states["pr"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'n')) {
      from = all_states["pri"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 't')) {
      from = all_states["prin"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'l')) {
      from = all_states["print"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'n')) {
      from = all_states["printl"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["println"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["p"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["pr"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["pri"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["prin"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["print"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["printl"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["println"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["p"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["pr"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["pri"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["prin"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["print"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["printl"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["println"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('r', all_states["r"]);
  from = all_states["r"];
  from->transitions.emplace('e', all_states["re"]);
  from = all_states["re"];
  from->transitions.emplace('t', all_states["ret"]);
  from = all_states["ret"];
  from->transitions.emplace('u', all_states["retu"]);
  from = all_states["retu"];
  from->transitions.emplace('r', all_states["retur"]);
  from = all_states["retur"];
  from->transitions.emplace('n', all_states["return"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'e')) {
      from = all_states["r"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 't')) {
      from = all_states["re"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'u')) {
      from = all_states["ret"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'r')) {
      from = all_states["retu"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'n')) {
      from = all_states["retur"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["return"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["r"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["re"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["ret"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["retu"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["retur"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["return"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["r"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["re"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["ret"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["retu"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["retur"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["return"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('N', all_states["N"]);
  from = all_states["N"];
  from->transitions.emplace('U', all_states["NU"]);
  from = all_states["NU"];
  from->transitions.emplace('L', all_states["NUL"]);
  from = all_states["NUL"];
  from->transitions.emplace('L', all_states["NULL"]);

  for (char c = 'A'; c <= 'Z'; c++) {
    if (!(c == 'U')) {
      from = all_states["N"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'L')) {
      from = all_states["NU"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'L')) {
      from = all_states["NUL"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["NULL"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'a'; c <= 'z'; c++) {
    from = all_states["N"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["NU"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["NUL"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["NULL"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["N"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["NU"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["NUL"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["NULL"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('n', all_states["n"]);
  from = all_states["n"];
  from->transitions.emplace('e', all_states["ne"]);
  from = all_states["ne"];
  from->transitions.emplace('w', all_states["new"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'e')) {
      from = all_states["n"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'w')) {
      from = all_states["ne"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["new"];
    from->transitions.emplace(c, all_states["id"]);
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["n"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["ne"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["new"];
    from->transitions.emplace(c, all_states["id"]);
  }
  for (char c = '0'; c <= '9'; c++) {
    from = all_states["n"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["ne"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["new"];
    from->transitions.emplace(c, all_states["id"]);
  }

  from = all_states["start"];
  from->transitions.emplace('d', all_states["d"]);
  from = all_states["d"];
  from->transitions.emplace('e', all_states["de"]);
  from = all_states["de"];
  from->transitions.emplace('l', all_states["del"]);
  from = all_states["del"];
  from->transitions.emplace('e', all_states["dele"]);
  from = all_states["dele"];
  from->transitions.emplace('t', all_states["delet"]);
  from = all_states["delet"];
  from->transitions.emplace('e', all_states["delete"]);

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'e')) {
      from = all_states["d"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'l')) {
      from = all_states["de"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'e')) {
      from = all_states["del"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 't')) {
      from = all_states["dele"];
      from->transitions.emplace(c, all_states["id"]);
    }
    if (!(c == 'e')) {
      from = all_states["delet"];
      from->transitions.emplace(c, all_states["id"]);
    }
    from = all_states["delete"];
    from->transitions.emplace(c, all_states["id"]);
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    from = all_states["d"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["de"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["del"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["dele"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["delet"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["delete"];
    from->transitions.emplace(c, all_states["id"]);
  }
  for (char c = '0'; c <= '9'; c++) {
    from = all_states["d"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["de"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["del"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["dele"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["delet"];
    from->transitions.emplace(c, all_states["id"]);
    from = all_states["delete"];
    from->transitions.emplace(c, all_states["id"]);
  }

  for (char c = 'a'; c <= 'z'; c++) {
    if (!(c == 'd' || c == 'e' || c == 'i' || c == 'n' || c == 'p' ||
          c == 'r' || c == 'w')) {
      from = all_states["start"];
      from->transitions.emplace(c, all_states["id"]);
    }
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    if (!(c == 'N')) {
      from = all_states["start"];
      from->transitions.emplace(c, all_states["id"]);
    }
  }

  for (char c = '1'; c <= '9'; c++) {
    from = all_states["start"];
    from->transitions.emplace(c, all_states["num"]);
  }

  for (char c = '0'; c <= '9'; c++) {
    from = all_states["num"];
    from->transitions.emplace(c, all_states["num"]);
  }

  from = all_states["start"];
  from->transitions.emplace('(', all_states["lparen"]);
  from = all_states["start"];
  from->transitions.emplace(')', all_states["rparen"]);
  from = all_states["start"];
  from->transitions.emplace('{', all_states["lbrace"]);
  from = all_states["start"];
  from->transitions.emplace('}', all_states["rbrace"]);
  from = all_states["start"];
  from->transitions.emplace('[', all_states["lbrack"]);
  from = all_states["start"];
  from->transitions.emplace(']', all_states["rbrack"]);
  from = all_states["start"];
  from->transitions.emplace('=', all_states["become"]);
  from = all_states["become"];
  from->transitions.emplace('=', all_states["eq"]);
  from = all_states["start"];
  from->transitions.emplace('!', all_states["ex"]);
  from = all_states["ex"];
  from->transitions.emplace('=', all_states["nne"]);
  from = all_states["start"];
  from->transitions.emplace('<', all_states["lt"]);
  from = all_states["lt"];
  from->transitions.emplace('=', all_states["le"]);
  from = all_states["start"];
  from->transitions.emplace('>', all_states["gt"]);
  from = all_states["gt"];
  from->transitions.emplace('=', all_states["ge"]);
  from = all_states["start"];
  from->transitions.emplace('+', all_states["plus"]);
  from = all_states["start"];
  from->transitions.emplace('-', all_states["minus"]);
  from = all_states["start"];
  from->transitions.emplace('*', all_states["star"]);
  from = all_states["start"];
  from->transitions.emplace('/', all_states["slash"]);
  from = all_states["start"];
  from->transitions.emplace('%', all_states["pct"]);
  from = all_states["start"];
  from->transitions.emplace(',', all_states["comma"]);
  from = all_states["start"];
  from->transitions.emplace(';', all_states["semi"]);
  from = all_states["start"];
  from->transitions.emplace('&', all_states["amp"]);

  try {
    while (getline(cin, s)) {
      stringstream x{s};
      State *cur = all_states[start_name];
      string ret = "";
      bool next = false;
      long val;

      while (x >> s) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
          if (s[i] == '/' && s[i + 1] == '/') {
            next = true;
            break;
          }

          if (cur->transitions.find(s[i]) == cur->transitions.end()) {
            if (cur->get_accepting()) {
              if (cur->get_token() == "NUM") {
                val = stol(ret, nullptr, 10);
                if (val > 2147483647) {
                  throw runtime_error("ERROR: Int too big");
                }
              }
              cout << cur->get_token() << ' ' << ret << endl;
              cur = all_states[start_name];
              ret = "";
              i -= 1;
            } else {
              throw runtime_error("ERROR: Not an Accepting State");
              return 0;
            }
          } else {
            cur = cur->transitions[s[i]];
            ret += s[i];
          }
        }

        if (next) {
          break;
        }

        if (cur->get_accepting()) {
          if (cur->get_token() == "NUM") {
            val = stol(ret, nullptr, 10);
            if (val > 2147483647) {
              throw runtime_error("ERROR: Int too big");
            }
          }
          cout << cur->get_token() << ' ' << ret << endl;
          ret = "";
          cur = all_states[start_name];
        } else {
          throw runtime_error("ERROR: Not an Accepting State");
        }
      }
    }
  } catch (runtime_error &error) {
    cerr << error.what() << endl;
  }

  for (auto i : all_states) {
    delete i.second;
  }
}
