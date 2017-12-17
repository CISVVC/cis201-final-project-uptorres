/**
* File name: main.cpp
* Developer: Erick Torres
* Email: erickt@rocketmail.com
* Description: This is the final project which should be a concordance generator that counts the repitition of words.
**/

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

int main()
{
	cout << "File name: "  << endl;
	char txtfile[100];
	ifstream a;
	cin.get(txtfile,100);
	a.open("alice.txt");

//reading file

	string inp;	//input
	string w;
	string text[2500];
	string words[2500];
	int l_num = 0 , l_set = 0; //line numbers place holder	
	int hold[1000];
	
	while(a.good())
	{
		int k;
		int i;
		getline(a, inp);
		for(i=0;i<inp.length();i++)
		{
	 	 /*  if(ispunct(inp[i]) && inp[i] != ' ' && inp[i] != '\n')
                   {
                    inp.erase(inp.begin()+i);
                    i--;    
                   }*/
		   if(!isalpha(inp.at(i)))
	           {
	            if(inp.at(i)!=' ')
	    	    for(int j=i;j<inp.length()-1;j++)
	   	    {
	    	      inp.at(j) = inp.at(j+1);
	 	    }
	  	    if(i==inp.length()-1)
	   	    inp.at(i) = ' ';
	 	   }

		   if(!islower(inp.at(i)))
	 	   {
	 	    inp.at(i) = tolower(inp.at(i));
	 	   }

	 	 }
		 
		 istringstream iss(inp);
		 while(iss>>w)
		 {
		   bool more = false;
		   int repeat = -1;
		   for(k=0;k<l_set;k++)
		   {
		    if(words[k]==w)
		    {
		     more = true;
	             repeat = k;
	            }
	           }
	
		   if(more!=true)
		   {
		    words[l_set] = w;
	            hold[l_set] = 1;
		  
		    stringstream ss;
		    ss<<l_num + 1;
		    text[l_set] = ss.str();
	            l_set++;
	           }
		   
		   else
		    {
		     hold[repeat]++;
		     stringstream ss2;
		     ss2<<l_num + 1;
		     text[repeat] = text[repeat] + ";"+ ss2.str();
		    }   
	
		 } 
 
	l_num = l_num + 1;
	}	
	
	cout<< "Words" << " : " << "Count" << " : " << "Line Number"<< endl;
	cout<< "===================================================================================================================================================================" << endl;
	cout<< "===================================================================================================================================================================" << endl;
	cout<< "===================================================================================================================================================================" << endl;
	
	
	for(int jj=0;jj<l_set;jj++)
	{
 cout<< words[jj] << " : " << hold[jj] <<  " : " << text[jj] << endl;
	}	
return 0;
}			
