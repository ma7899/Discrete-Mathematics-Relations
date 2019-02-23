#include <iostream>
#include <list>
#include<algorithm>
using namespace std;


bool isReflexive(pair<int,int> x[] , int ind , int set[] , int setind);
bool isSymmetric(pair<int,int> x[] , int ind);
bool isAnti_Symmetric(pair<int,int> x[], int ind);
bool isTransitive(pair<int,int> x[] , int ind);
bool isAnti_Symmetric(int[],char);
bool isinrel(pair<int,int> x[] , int ind , int firstnum , int secnum );
void printset(pair<int,int> x[] ,int seq_ind);
void printunionR1R2(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind);
void printintersectionR1R2(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind);
void printdifferenceR2R1(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind);
void printdifferenceR1R2(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind);
void printcombine(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind);
void printdelta(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind);
void menu();



int main()
{
    pair<int,int> R1[10000];
    pair<int,int> R2[10000];
    int ind=0,seq_ind=0,R1_ind=0,R2_ind=0,check=0;;
    int num;
    int set[100];
    pair<int,int> seq[10000];
    string command;
    int secnum,firstnum;    //for checking the relation between 2 numbers of set
    bool flag;


    cout<<"Enter the set(Enter <done> to end):"<<endl;

    while(true)                                   //daryafte majmooe
    {
        cin>> command;
        if(command == "done")break;
        else
        {
            num = stoi(command);
            set[ind]=num;
            ind++;
        }
    }

    for(int i=0;i<ind;i++)                        //sakhte majmooe
    {
        for(int j=0;j<ind;j++)
        {
            seq[seq_ind].first=set[i];
            seq[seq_ind].second=set[j];
            seq_ind++;
        }
    }

    cout<<endl;
    cout<<"Enter the first relation:(Enter <done> to end)"<<endl;          //Rabete ye aval ra az karbar migirad va baraye etmam <done> ra vared mikonad

    while(true)
    {

        cin>> command;
        check++;
        if(command == "done")break;
        else
        {
            num = stoi(command);
            if(check % 2 == 1) R1[R1_ind].first=num;
            else
            {
                R1[R1_ind].second=num;
                R1_ind++;
            }

        }
    }

    cout<<endl;
    cout<<"Enter the second relation:(Enter <done> to end)"<<endl;          //Rabete ye dovom ra az karbar migirad va baraye etmam <done> ra vared mikonad
    check=0;
    while(true)
    {
        cin>> command;
        check++;
        if(command == "done")break;
        else
        {
            num = stoi(command);
            if(check%2 == 1) R2[R2_ind].first=num;
            else
            {
                R2[R2_ind].second=num;
                R2_ind++;
            }

        }
    }

    system("CLS");
    menu();

    while(true)
    {
        cin>>command;
        if(command == "9")break;
        else
        {
            if(command == "8")
            {
                system("CLS");
                menu();
            }
            else if(command == "7")
            {
                cout<<"R1=";
                printset(R1,R1_ind);
                cout<<"R2=";
                printset(R2,R2_ind);
            }
            else if(command == "6")
            {
                cout<<"Set=";
                printset(seq,seq_ind);
            }
            else if(command == "5")
            {
                printdelta(R1,R2,R1_ind,R2_ind);
            }
            else if(command == "4")
            {
                cout<<"Enter the first number:";
                cin>>firstnum;
                cout<<"Enter the second number";
                cin>>secnum;
                flag=isinrel(R1,R1_ind,firstnum,secnum);
                cout<<"--------------------------"<<endl;
                if(flag)cout<<"Is in relation1"<<endl;
                else cout<<"Is not in relation1"<<endl;
                flag=isinrel(R2,R2_ind,firstnum,secnum);
                if(flag)cout<<"Is in relation2"<<endl;
                else cout<<"Is not in relation2"<<endl;
                cout<<"--------------------------"<<endl;
            }
            else if (command == "3")
            {
                cout<<"R1 O R2=";
                printcombine(R1,R2,R1_ind,R2_ind);
                cout<<"R2 O R1=";
                printcombine(R2,R1,R2_ind,R1_ind);
            }
            else if(command == "2")
            {
                printunionR1R2(R1,R2,R1_ind,R2_ind);
                printintersectionR1R2(R1,R2,R1_ind,R2_ind);
                printdifferenceR2R1(R1,R2,R1_ind,R2_ind);
                printdifferenceR1R2(R1,R2,R1_ind,R2_ind);
            }
            else if(command == "1")
            {
                cout<<"--------------------------"<<endl;
                flag=isReflexive(R1,R1_ind,set,ind);
                if(flag)cout<<"Relation1 is Reflexive"<<endl;
                else cout<<"Relation1 is not Reflexive"<<endl;
                flag=isSymmetric(R1,R1_ind);
                if(flag)cout<<"Relation1 is Symmetric"<<endl;
                else cout<<"Relation1 is not Symmetric"<<endl;
                flag=isAnti_Symmetric(R1,R1_ind);
                if(flag)cout<<"Relation1 is Anti-Symmetric"<<endl;
                else cout<<"Relation1 is not Anti-Symmetric"<<endl;
                flag=isTransitive(R1,R1_ind);
                if(flag)cout<<"Relation1 is Transitive"<<endl;
                else cout<<"Relation1 is not Transitive"<<endl;


                cout<<"--------------------------"<<endl;
                flag=isReflexive(R2,R2_ind,set,ind);
                if(flag)cout<<"Relation2 is Reflexive"<<endl;
                else cout<<"Relation2 is not Reflexive"<<endl;
                flag=isSymmetric(R2,R2_ind);
                if(flag)cout<<"Relation2 is Symmetric"<<endl;
                else cout<<"Relation2 is not Symmetric"<<endl;
                flag=isAnti_Symmetric(R2,R2_ind);
                if(flag)cout<<"Relation2 is Anti-Symmetric"<<endl;
                else cout<<"Relation2 is not Anti-Symmetric"<<endl;
                flag=isTransitive(R2,R2_ind);
                if(flag)cout<<"Relation2 is Transitive"<<endl;
                else cout<<"Relation2 is not Transitive"<<endl;


            }
        }
    }




    return 0;
}





void menu()
{
    cout<<"Enter the number of your command:"<<endl;
    cout<<"1-Checking the relations\n"
          "2-union,intersection and difference of relations\n"
          "3-Combine of relations\n"
          "4-Checking realations on 2 units of set\n"
          "5-Symmetric difference of the relations\n"
          "6-Print the set\n"
          "7-Print the relations\n"
          "8-Menu\n"
          "9-Exit"<<endl;
}
void printset(pair<int,int> x[] ,int seq_ind)
{
      cout<<"{";
        for(int i=0;i<seq_ind-1;i++)
            cout<<"("<<x[i].first<<","<<x[i].second<<"),";
        if(seq_ind>0)
        {
            cout<<"("<<x[seq_ind-1].first<<","<<x[seq_ind-1].second<<")";
        }
        cout<<"}"<<endl;

}
void printunionR1R2(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind)
{
    bool flag;
    int R3_ind;
    pair<int,int> R3[10000];
    R3_ind = R1_ind;
    for(int i =0;i<R1_ind;i++)
        R3[i]=R1[i];
    for(int i =0;i<R2_ind;i++)
    {
        flag=true;
        for(int j =0;j<R1_ind;j++)
            if((R1[j].first==R2[i].first)&&(R1[j].second==R2[i].second))
            {
                flag=false;
                break;
            }
        if(flag)
        {
            R3[R3_ind].first=R2[i].first;
            R3[R3_ind].second=R2[i].second;
            R3_ind++;
        }
    }

    cout<<"UnionR1R2=";
    printset(R3,R3_ind);

}
void printintersectionR1R2(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind)
{
    int R3_ind=0;
    pair<int,int> R3[10000];
    for(int i =0;i<R2_ind;i++)
        for(int j =0;j<R1_ind;j++)
        {
            if((R1[j].first==R2[i].first)&&(R1[j].second==R2[i].second))
            {
                R3[R3_ind].first=R2[i].first;
                R3[R3_ind].second=R2[i].second;
                R3_ind++;
                break;
            }
        }
    cout<<"intersectionR1R2=";
    printset(R3,R3_ind);
}
void printdifferenceR2R1(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind)
{
    bool flag=true;
    int R3_ind=0;
    pair<int,int> R3[10000];
    for(int i =0;i<R2_ind;i++)
    {
        flag=true;
        for(int j =0;j<R1_ind;j++)
            if((R1[j].first==R2[i].first)&&(R1[j].second==R2[i].second))
            {
                flag=false;
                break;
            }
        if(flag)
        {
            R3[R3_ind].first=R2[i].first;
            R3[R3_ind].second=R2[i].second;
            R3_ind++;
        }
    }
    cout<<"differenceR2R1=";
    printset(R3,R3_ind);
}
void printdifferenceR1R2(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind)
{
    bool flag=true;
    int R3_ind=0;
    pair<int,int> R3[10000];
    for(int i =0;i<R1_ind;i++)
    {
        flag=true;
        for(int j =0;j<R2_ind;j++)
            if((R2[j].first==R1[i].first)&&(R2[j].second==R1[i].second))
            {
                flag=false;
                break;
            }
        if(flag)
        {
            R3[R3_ind].first=R1[i].first;
            R3[R3_ind].second=R1[i].second;
            R3_ind++;
        }
    }
    cout<<"differenceR1R2=";
    printset(R3,R3_ind);
}
bool isinrel(pair<int,int> x[] , int ind , int firstnum , int secnum )
{
    for(int i=0;i<ind;i++)
        if(x[i].first==firstnum)
            if(x[i].second==secnum)
                return true;
    return false;
}
bool isReflexive(pair<int,int> x[] , int ind , int set[] , int setind )
{
    int cnt=0;
    for(int i=0 ; i<setind ; i++)
    {
        for(int j=0 ; j<ind ; j++)
            if((set[i]==x[j].first)&&(set[i]==x[j].second))
            {
                cnt++;
                break;
            }
    }
    if(cnt==setind)
        return true;
    else return false;
}
bool isSymmetric(pair<int,int> x[] , int ind)
{
    int first;
    int second;
    int cnt=0;
    for(int i=0;i<ind;i++)
    {
        first=x[i].first;
        second=x[i].second;
        for(int j=0;j<ind;j++)
            if((x[j].first==second)&&(x[j].second==first))
            {
                cnt++;
                break;
            }
    }
    if(cnt==ind)
        return true;
    else return false;
}
bool isAnti_Symmetric(pair<int,int> x[], int ind)
{
    int first;
    int second;
    for(int i=0;i<ind;i++)
    {
        first=x[i].first;
        second=x[i].second;
        for(int j=0;j<ind;j++)
            if((x[j].first==second)&&(x[j].second==first))
                if(first!=second)
                    return false;
    }
    return true;
}
bool isTransitive(pair<int,int> x[] , int ind)
{
    bool flag=true;
    int first;
    int second;
    int third;
    for(int i=0;i<ind;i++)
    {
        first=x[i].first;
        second=x[i].second;
        for(int j=0;j<ind;j++)
            if(x[j].first==second)
            {
                third=x[j].second;
                for(int k=0;k<ind;k++)
                {
                    if((x[k].first==first)&&(x[k].second==third))
                    {
                        flag=true;
                        break;
                    }
                    else
                    {
                        flag=false;
                    }
                }
                if(flag == false)return false;
            }
     }
    return flag;
}
void printcombine(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind)
{
    pair<int,int> R3[10000];
    int R3_ind=0;
    for(int i=0;i<R1_ind;i++)
    {
        for(int j=0;j<R2_ind;j++)
        {
            if(R1[i].second==R2[j].first)
            {
                R3[R3_ind].first=R1[i].first;
                R3[R3_ind].second=R2[j].second;
                R3_ind++;
            }
        }
    }
    printset(R3,R3_ind);
}
void printdelta(pair<int,int> R1[],pair<int,int> R2[],int R1_ind,int R2_ind)
{
    bool flag=true;
    int R3_ind=0;
    pair<int,int> R3[10000];
    for(int i =0;i<R2_ind;i++)
    {
        flag=true;
        for(int j =0;j<R1_ind;j++)
            if((R1[j].first==R2[i].first)&&(R1[j].second==R2[i].second))
            {
                flag=false;
                break;
            }
        if(flag)
        {
            R3[R3_ind].first=R2[i].first;
            R3[R3_ind].second=R2[i].second;
            R3_ind++;
        }
    }


    for(int i =0;i<R1_ind;i++)
    {
        flag=true;
        for(int j =0;j<R2_ind;j++)
            if((R2[j].first==R1[i].first)&&(R2[j].second==R1[i].second))
            {
                flag=false;
                break;
            }
        if(flag)
        {
            R3[R3_ind].first=R1[i].first;
            R3[R3_ind].second=R1[i].second;
            R3_ind++;
        }
    }
    cout<<"R1deltaR2=";
    printset(R3,R3_ind);
}
