#include <iostream>
#include <string.h>
using namespace std;

class StringOperaions{
    std::string str, pat, rep, fstr;
    int start=0, patFound=0;
    int ls,lp,lr;
    public:
        StringOperaions(std::string string1,std::string pattern,std::string repstring){
            str=string1;
            pat=pattern;
            rep=repstring;
            lr = rep.length()-1;
            ls = str.length()-1;
            lp = pat.length()-1;
        }
        void dispstr(){
            cout << fstr;
        }

        void replacpattern(){
            int i, j;
            if(lp != lr){
                cout << "\n Invalid replace string\n";
                exit(0);
            }
            else {
                i = start;
                for(j=0;j<lr+1;j++){
                    str[i]=rep[j];
                    i++;
                }
                fstr=str;
            }
            return;
        }

        int findpattern(){
            int i, j, inmatch, endmatch;
            for(endmatch=lp; endmatch<=ls; endmatch++, start++){
                if(str[endmatch]==pat[lp]){
                    inmatch=start;
                    j=0;
                    while(j<=lp){
                        if(str[inmatch]==pat[j]){
                            inmatch++;
                            j++;
                        }
                        else{
                            break;
                        }
                        if(j==lp){
                            patFound=1;
                            replacpattern();
                        }
                    }
                }
            }
           return patFound;
        }
};

int main(){
    std::string str, pat, rep;
    cout << "enter the main string str\n";
    cin >> str;
    cout << "enter the main pattern sring pat\n";
    cin >> pat;
    cout << "enter the replace string rep\n";
    cin >> rep;
    cout << "the string before pattern match is \t" << str;
    StringOperaions strop(str, pat, rep);
    if(strop.findpattern()){
        cout <<"\nThe pattern found\nThe string after pattern match is \t";
        strop.dispstr();
        cout << endl;
    }
    else {
        cout << "pattern ptr not found in str\n";
    }
    return 0;
}