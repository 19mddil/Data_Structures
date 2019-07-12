/**
    Thanks to Allah
    One chicky code which I did by the proper using of
    debuging and break and conitinue
**/
#include<iostream>
#include<cstdlib>
using namespace std;

bool substr_src(string text,string pattern){
    int i=0,j=0;
    bool x;
    int temp;
    int p = pattern.length();
    int count=0;
    while(pattern[j] != '\0' && text[i] != '\0'){///trying to match first char of pattern in the text
        if(pattern[j] == text [i]){///if first character match is found
            temp = i;///saving i so that later we can start from here
            for(j=0;j<p;j++){
                if(pattern[j] != text[i]){///if a char in pattern doesnt similar to text
                    i = temp+1;
                    j = 0;
                    break;
                }
                else{
                    i++;
                    count++;
                }
            }
            continue;
        }
        i++;
    }
    if(count == pattern.length()){
        x = true;
        return x;
    }
    else{
        x = false;
        return x;
    }
}
int main(){
    cout<<boolalpha<<substr_src("meow","me");
}
