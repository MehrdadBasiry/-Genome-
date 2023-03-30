//<<Library>>
#include<iostream>
#include<string>
using namespace std;
//<<Class Genome>>
class Genome1 {
private:
    string RNA1, DNA1, DNA2;
public:
    //<<constructor>>
    Genome1(string rna1, string dna1, string dna2) {
        this->RNA1 = rna1;
        this->DNA1 = dna1;
        this->DNA2 = dna2;
    }
    string Gene1() {
        //<<Function DNA By RNA>>
        string G1 = "";
        for (int i = 0; i < this->RNA1.length(); i++) {
            if (this->RNA1[i] == 'A') {
                G1 += 'T';
            }
            else if (this->RNA1[i] == 'G') {
                G1 += 'C';
            }
            else if (this->RNA1[i] == 'C') {
                G1 += 'G';
            }
            else if (this->RNA1[i] == 'T') {
                G1 += 'A';
            }
        }
        this->DNA1 = G1;
        return DNA1;
    }
    //<<Function Small Mutation>>
    void Small(int q, char Insert_Word, char Word, int h) {
        int z = 0;
        string New1, New2;
        //<<RNA Part>>
        if (q == 1) {
            cout << "RNA:" << RNA1;
            for (int i = 0; i < RNA1.length(); i++) {
                if (RNA1[i] == Word && z != h) {
                    New1 += Insert_Word;
                    z++;
                }
                else {
                    New1 += RNA1[i];
                }
            }
            cout << endl << "Small Mutation:" << New1;
        }
        //<<DNA Part>>
        else if (q == 2) {
            char M;
            cout << "DNA:" << DNA1 << endl << "    " << DNA2 << endl;
            if (Insert_Word == 'T') {
                M = 'A';
            }
            else if (Insert_Word == 'G') {
                M = 'C';
            }
            else if (Insert_Word == 'C') {
                M = 'G';
            }
            else if (Insert_Word == 'A') {
                M = 'T';
            }
            for (int i = 0; i < DNA2.length(); i++) {
                if (DNA1[i] == Word) {
                    DNA1[i] = Insert_Word;
                    DNA2[i] = M;
                    z++;
                }
                else if (DNA2[i] == Word) {
                    DNA2[i] = Insert_Word;
                    DNA1[i] = M;
                    z++;
                }
                if (z == h) {
                    break;
                }
            }
            cout << "Small Mutation:" << DNA1 << endl << "               " << DNA2;
        }
    }
    //<<Function Great Mutation>>
    void Great(int e, string Phrase, string Insert_Phrase) {
        int Index1, Index2;
        string G2, New1, New2, k1, k2;
        //<<RNA Part>>
        if (e == 1) {
            for (int i = 0; i < RNA1.length(); i++) {
                Index1 = RNA1.find(Phrase);
            }
            cout << "RNA:" << RNA1;
            RNA1.replace(Index1, Phrase.length(), Insert_Phrase);
            cout << endl << "Great Mutation:" << RNA1;
        }
        //<<DNA Part>>
        else if (e == 2) {
            for (int i = 0; i < DNA1.length(); i++) {
                Index1 = DNA1.find(Phrase);
            }
            for (int i = 0; i < DNA2.length(); i++) {
                Index2 = DNA2.find(Phrase);
            }
            if (Index1 > Index2 || Index1==-1) {
                for (int i = 0; i < Insert_Phrase.length(); i++) {
                    if (Insert_Phrase[i] == 'A') {
                        G2 += 'T';
                    }
                    else if (Insert_Phrase[i] == 'T') {
                        G2 += 'A';
                    }
                    else if (Insert_Phrase[i] == 'C') {
                        G2 += 'G';
                    }
                    else if (Insert_Phrase[i] == 'G') {
                        G2 += 'C';
                    }
                }
                cout << "DNA:" << DNA1 << endl << "    " << DNA2;
                DNA2.replace(Index2, Phrase.length(), Insert_Phrase);
                DNA1.replace(Index2, Phrase.length(), G2);
                cout << endl << "Great Mutation:" << DNA1 << endl << "               " << DNA2;
            }
            else if (Index1 < Index2 || Index2==-1) {
                for (int i = 0; i < Insert_Phrase.length(); i++) {
                    if (Insert_Phrase[i] == 'A') {
                        G2 += 'T';
                    }
                    else if (Insert_Phrase[i] == 'T') {
                        G2 += 'A';
                    }
                    else if (Insert_Phrase[i] == 'C') {
                        G2 += 'G';
                    }
                    else if (Insert_Phrase[i] == 'G') {
                        G2 += 'C';
                    }
                }
                cout << "DNA:" << DNA1 << endl << "    " << DNA2;
                DNA1.replace(Index1, Phrase.length(), Insert_Phrase);
                DNA2.replace(Index1, Phrase.length(), G2);
                cout << endl << "Great Mutation:" << DNA1 << endl << "               " << DNA2;
            }
        }
    }
    //<<Function Reversed Mutation>>
    void Reversed(int w, string Rev_Part) {
        int Index1;
        string reversed_bio,reversed_bio2;
        for (int i = Rev_Part.length() - 1; i >= 0; i--) {
            reversed_bio += Rev_Part[i];
        }
        for (int i = 0; i < reversed_bio.length(); i++) {
            if (reversed_bio[i] == 'A') {
                reversed_bio2 += 'T';
            }
            else if (reversed_bio[i] == 'T') {
                reversed_bio2 += 'A';
            }
            else if (reversed_bio[i] == 'C') {
                reversed_bio2 += 'G';
            }
            else if (reversed_bio[i] == 'G') {
                reversed_bio2 += 'C';
            }
        }
        //<<RNA Part>>
        if (w == 1) {
            Index1 = RNA1.find(Rev_Part);
            cout << "RNA:" << RNA1;
            RNA1.replace(Index1, Rev_Part.length(), reversed_bio);
            cout << endl << "Reversed RNA:" << RNA1;
        }
        //<<DNA Part>>
        else if (w == 2) {
            if(DNA1.find(Rev_Part)!=-1){
                Index1=DNA1.find(Rev_Part);
                cout << "DNA:" << DNA1 << endl << "    " << DNA2;
                DNA1.replace(Index1,Rev_Part.length(),reversed_bio);
                DNA2.replace(Index1,Rev_Part.length(),reversed_bio2);
                cout << endl << "Reversed Mutation:" << DNA1 << endl << "                  " << DNA2;
            }
            else if(DNA2.find(Rev_Part)!=-1){
                Index1=DNA2.find(Rev_Part);
                cout << "DNA:" << DNA1 << endl << "    " << DNA2;
                DNA2.replace(Index1,Rev_Part.length(),reversed_bio);
                DNA1.replace(Index1,Rev_Part.length(),reversed_bio2);
                cout << endl << "Reversed Mutation:" << DNA1 << endl << "                  " << DNA2;
            }
        }
    }
};
//<<Main Function>>
int main() {
    cout << "<< Biology Experiment >>" << endl;
    int a;
    string bio, DNA2, DNA3, k1, k2;
    while(true) {
        cout << "Enter Your RNA:";
        cin >> bio;
        cout << "Enter Your DNA(S1):";
        cin >> DNA2;
        k1 = DNA2;
        cout << "Enter Your DNA(S2):";
        cin >> DNA3;
        k2 = DNA3;
        Genome1 Genetic1(bio, DNA2, DNA3);
        cout << "1>>(Build DNA By RNA)" << endl << "2>>(Small Mutation)" << endl << "3>>(Great Mutation)" << endl
             << "4>>(Reversed Mutation)" << endl;
        cout << "Choose A Num:";
        cin >> a;
        //<<Build DNA By RNA Code>>
        if (a == 1) {
            //<<Build DNA By RNA Run>>
            cout << "RNA:" << bio << endl << "DNA:" << bio << endl << "    " << Genetic1.Gene1()<<endl;
        }
            //<<Small Mutation Code>>
        else if (a == 2) {
            int q, h, z = 0;
            string New1, New2;
            char Word, Insert_Word, M;
            cout << "1>>(RNA)" << endl << "2>>(DNA)" << endl;
            cout << "Choose A Num:";
            cin >> q;
            cout << "Word:";
            cin >> Word;
            cout << "Insert_Word:";
            cin >> Insert_Word;
            cout << "How Many Times:";
            cin >> h;
            //<<Small Mutation Run>>
            Genetic1.Small(q, Insert_Word, Word, h);
            cout<<endl;
        }
            //<<Great Mutation Code>>
        else if (a == 3) {
            int e, Index1, Index2;
            string New1, New2, Phrase, Insert_Phrase, W, G2;
            cout << "1>>(RNA)" << endl << "2>>(DNA)" << endl;
            cout << "Choose A Num:";
            cin >> e;
            cout << "Phrase:";
            cin >> Phrase;
            cout << "Insert_Phrase:";
            cin >> Insert_Phrase;
            //<<Great Mutation Run>>
            Genetic1.Great(e, Phrase, Insert_Phrase);
            cout<<endl;
        }
            //<<Reversed Mutation Code>>
        else if (a == 4) {
            int w, Index1, Index2;
            string Rev_Part, R1, R2, k3, k4, k5;
            k3 = bio;
            k4 = DNA2;
            k5 = DNA3;
            cout << "1>>(RNA)" << endl << "2>>(DNA)" << endl;
            cout << "Choose A Num:";
            cin >> w;
            cout << "Reversed Part:";
            cin >> Rev_Part;
            //<<Reversed Mutation Run>>
            Genetic1.Reversed(w, Rev_Part);
            cout<<endl;
        }
    }
    return 0;
}

