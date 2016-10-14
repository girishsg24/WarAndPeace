#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
using namespace std;


void findName(string line,string name,int line_count);
void findsplitNames(string line,string firstname,vector<string>&combinedname,int index);
void printsplitnames(vector<string>&firstnameandpos,int index,int lineNum,string line,vector<string>&person,vector<string>&lastnames);
string intToString(int num);

int main()
{
  vector<string>firstnames;
  firstnames.push_back("Makar");
  firstnames.push_back("Boris");
  firstnames.push_back("Joseph");

  vector<string>lastnames;
  lastnames.push_back("Alexeevich");
  lastnames.push_back("Drubetskoy");
  lastnames.push_back("Bazdeev");

  vector<string>person;
  person.push_back("Makar Alexeevich");
  person.push_back("Boris Drubetskoy");
  person.push_back("Joseph Bazdeev");
  
  ifstream warandpeace;        
   
  string line="";
     
  vector<string>combined(6," ");
  size_t splitfind;
  int line_count=0,position=0;
  warandpeace.open("WarAndPeace.txt");
     
     
  if( warandpeace.fail())
  {
    cout<<"Failed to open"<<endl;
    return -1;
  }
     
  cout<<setw(5)<<"LINE"<<"\t"<<"POSITION"<<setw(8)<<"NAME"<<endl;
     
  while(getline(warandpeace,line))
  {
    for(int i=0,len=combined.size();i<len;i=i+2)
    {
      printsplitnames(combined,i, line_count,line,person,lastnames); 
    } 
       
    line_count++;
       
    for(int i=0,len=person.size();i<len;i++)
    {
      findName(line,person[i],line_count);
    }
       
    for(int i=0,j=0,ilen=firstnames.size();i<ilen;i++,j=j+2)
    {
      findsplitNames(line,firstnames[i],combined,j);
    }
      
   }
     warandpeace.close();
 }
 
void findName(string line,string name,int line_count)
{
  size_t found;
  found=line.find(name);
  if (found!=string::npos)
  {
    cout<<line_count<<"\t"<<setw(8)<<found+1<<setw(20)<<name<<endl;
  } 
}

void findsplitNames(string line,string firstname,vector<string>&combinedname,int index)
{
  int position=line.find(firstname);
  if ((position!=string::npos )&&(line[position+firstname.length()]=='\0'))
  {
   combinedname[index]=firstname;
   position++;
   combinedname[index+1]=intToString(position);
  }
  else
  {
   combinedname[index]=" ";
   combinedname[index+1]=" ";
  }
}
 
void printsplitnames(vector<string>&firstnameandpos,int index,int lineNum,string line,vector<string>&person,vector<string>&lastnames) 
{
  if (firstnameandpos[index]!=" ")
  {
    int j=0;
    if (index==2)
    {
      j=index-1;
    }
    else if (index==4)
    {
     j=index-2;
    }
    
    int splitfind=line.find(lastnames[j]);
    if (splitfind==0)
    {
      cout<<lineNum<<"\t"<<setw(8)<<atoi(firstnameandpos[index+1].c_str())<<setw(20)<<person[j]<<"\t"<<endl;
    }
  }
}


string intToString(int num)
{ 
  stringstream ss;
  ss<<num<<endl;
  string convertedInt=ss.str();
  return convertedInt;
} 
 
 