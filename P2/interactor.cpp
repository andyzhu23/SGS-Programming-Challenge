#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

// modified from a template by wleung_bvg

namespace Reader {
    const int ERROR_COUNT = 4;

    enum error_type {
        INTERNAL_RANGE = 0, EXTERNAL_RANGE, INVALID_ARGUMENT, WRONG_WHITESPACE
    };

    const char *error_names[ERROR_COUNT] = {"INTERNAL_RANGE", "EXTERNAL_RANGE", "INVALID_ARGUMENT", "WRONG_WHITESPACE"};

    typedef void __attribute__((noreturn)) (*error_handler)(enum error_type e);

    void __attribute__((noreturn)) runtime_error_handler(error_type e) {
        if (e >= ERROR_COUNT) throw runtime_error("Unknown error in FileReader");

        throw runtime_error(error_names[e]);
    }

    class FileReader {

    private:
        FILE *stream;

        bool hasLast;
        char lastChar;

        error_handler handler;

    public:
        FileReader(FILE *f, error_handler handler) : stream(f), hasLast(false), lastChar(0), handler(handler) {}

        char peekChar() {
            if (!hasLast) {
                lastChar = getc(stream);
                hasLast = true;
            }
            return lastChar;
        }

        char readChar() {
            char ret = peekChar();
            hasLast = false;
            return ret;
        }


        bool eof() {
            return peekChar() == char_traits<char>::eof();
        }

        void trim() {
            while (isspace(peekChar()) && !eof()) {
                readChar();
            }
        }

        ll readInt(ll minValid, ll maxValid) {
            string token = "";
            while (isdigit(peekChar()) || peekChar() == '-') token.push_back(readChar());
            try {
                ll ret = stoll(token);

                if (minValid > ret || maxValid < ret) handler(INTERNAL_RANGE);

                return ret;
            }
            catch (const out_of_range &e) {
                handler(EXTERNAL_RANGE);
            }
            catch (const invalid_argument &e) {
                handler(INVALID_ARGUMENT);
            }
        }

        ld readFloat(ld minValid, ld maxValid) {
            string token = "";
            while (isdigit(peekChar()) || peekChar() == '-' || peekChar() == '.') token.push_back(readChar());

            try {
                ld ret = stold(token);

                if (minValid > ret || maxValid < ret) handler(INTERNAL_RANGE);

                return ret;
            }
            catch (const out_of_range &e) {
                handler(EXTERNAL_RANGE);
            }
            catch (const invalid_argument &e) {
                handler(INVALID_ARGUMENT);
            }
        }

        string readFile() {
            string ret = "";
            while (!eof()) {
                ret.push_back(readChar());
            }

            readEOF();

            return ret;
        }

        string readString(int N) {
            string ret = "";
            for (int i = 0; i < N; i++) {
                ret.push_back(readChar());
            }

            return ret;
        }

        string readLine() {
            string ret = "";
            while (peekChar() != '\n' && !eof()) ret.push_back(readChar());
            readNewLine();

            return ret;
        }

        void readSpace() {
            if (readChar() != ' ') handler(WRONG_WHITESPACE);
        }

        void readNewLine() {
            if (readChar() != '\n') handler(WRONG_WHITESPACE);
        }

        void readEOF() {
            if (readChar() != char_traits<char>::eof()) handler(WRONG_WHITESPACE);
        }

        string readToken() {
            string token = "";

            while (!isspace(peekChar()) && !eof()) token.push_back(readChar());

            return token;
        }

    private:
        template<typename T>
        T &_fill_arr(T &res, int N, ll lo, ll hi) {
            for (int i = 0; i < N; i++) {
                res[i] = readInt(lo, hi);

                if (i == N - 1) readNewLine();
                else readSpace();
            }

            return res;
        }

    public:
        template<int length>
        array<ll, length> readIntTuple(ll lo, ll hi) {
            array<ll, length> res;

            return _fill_arr(res, length, lo, hi);
        }

        vector<ll> readIntArray(int N, ll lo, ll hi) {
            vector<ll> res(N, 0);

            return _fill_arr(res, N, lo, hi);
        }
    };
}

using Reader::FileReader;

namespace CheckerCodes {
    int AC = 0;
    int WA = 1;
    int PE = 2;
    int IE = 3;
    int PARTIAL = 7;
}

void __attribute__((noreturn)) checker_handler(enum Reader::error_type e) {
    switch (e) {
        case Reader::error_type::INTERNAL_RANGE:
        case Reader::error_type::EXTERNAL_RANGE:
            puts("-1");
            exit(CheckerCodes::WA);

        case Reader::error_type::WRONG_WHITESPACE:
        case Reader::error_type::INVALID_ARGUMENT:
            puts("-1");
            exit(CheckerCodes::PE);

        default:
            puts("-1");
            exit(CheckerCodes::IE);
    }
}

int n, lim;
long long cnt;
bool flag;
vector<int> a;
vector<pii> b;

int main(int argc, char **argv) {
    Reader::FileReader in_r(fopen(argv[1], "r"), Reader::runtime_error_handler), prog_r(stdin, checker_handler);

    n = in_r.readInt(0, 100000);
    lim = n * 6;
    in_r.readNewLine();
    for(int i = 1;i<=n;++i) {
        a.push_back(in_r.readInt(-(int)1e9, (int)1e9));
        if(i < n) in_r.readSpace();
    }
    cout << n << endl;

    int cost = 0;
    while (true) {
        char c = prog_r.readChar();
        if (!(((c == '?' || c == '$') && cost <= lim) || c == '!')) {
            cout << "-1" << endl;
            return CheckerCodes::WA;
        }
        if (c == '?') {
            prog_r.readSpace();
            int l = prog_r.readInt(0, n - 1) + 1;
            prog_r.readSpace();
            int r = prog_r.readInt(0, n - 1) + 1;
            prog_r.readNewLine();
            ++cost;
            cout << (a[l - 1] > a[r - 1]) << endl;
        } else if (c == '$') {
            prog_r.readSpace();
            int m = prog_r.readInt(1, n);
            set<int> vis;
            b.clear();
            for(int i = 1;i<=m;++i) {
                prog_r.readSpace();
                int tmp = prog_r.readInt(0, n - 1) + 1;
                if(vis.count(tmp)) {
                    cout << "-1" << endl;
                    return CheckerCodes::WA;
                }
                vis.insert(tmp);
                b.push_back({a[tmp - 1], tmp});
            }
            prog_r.readSpace();
            int x = prog_r.readInt(0, m - 1);
            sort(b.begin(), b.end());
            cost += m;
            cout << b[x].second - 1 << endl;
            prog_r.readNewLine();
        } else {
            b.clear();
            for(int i = 0;i<a.size();++i) b.push_back({a[i], i + 1});
            sort(b.begin(), b.end());
            vector<int> ans;
            int x = 1;
            while(x < b.size()) {
                ans.push_back(b[x].second);
                x <<= 1;
            }
            prog_r.readSpace();
            int k = prog_r.readInt(0, n);
            if(k != ans.size() - 1) {
                cout << "-1" << endl;
                return CheckerCodes::WA;
            }
            for(int i = 0;i<=k;++i) {
                prog_r.readSpace();
                int x = prog_r.readInt(0, n - 1) + 1;
                if(x != ans[i]) {
                    cout << "-1" << endl;
                    return CheckerCodes::WA;
                }
            }
            break;
        }
    }
    return CheckerCodes::AC;
}
