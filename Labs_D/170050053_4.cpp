#include<iostream>
#include<string>
#include<unordered_map>
//g++ -std=c++0x source.cxx   compile 
using namespace std;



int part1(string s, int k){
	int q = s.length()/k;   //each string size
	string set[k];      //set of strings 
	unordered_map<string, int> strFreq;    //string frequency map
                    
    string s1 =s ;                        // safety string 
	for(int i=0; i<s1.length(); i+=q){   
		int index = i/q;
		set[index] = s1.substr(0, q);   //filling set with Sub string
		strFreq[s1.substr(0, q)] +=1;   //updating unordered map
		s1.erase(s1.begin(), s1.begin()+q);   //erasing sub strings taken 
	}

	unordered_map<string, int>:: iterator itr;   //iterator 

	string maxFreqStr = set[0];             // finding max frequency string in set 
	int maxFreq = strFreq[set[0]];       // and its frequency      
	for (itr = strFreq.begin(); itr != strFreq.end(); itr++){
		if(itr->second >= maxFreq){
			maxFreq = itr->second;
			maxFreqStr = itr->first;
		}
	}

    int counter =0;     //number of replacements 
    for(int i=0; i<k; i++){
    	if(set[i] == maxFreqStr)
    		counter = counter;
    	else{
    		string tempMax = maxFreqStr, tempSet = set[i];

    		for(int j=0; j<q; j++){
    			if(tempMax.substr(0, 1) == tempSet.substr(0,1)){
    				counter = counter;
    				tempMax.erase(tempMax.begin(), tempMax.begin()+1);
    				tempSet.erase(tempSet.begin(), tempSet.begin()+1);
    			}
    			else{
    				counter +=1;
    				tempMax.erase(tempMax.begin(), tempMax.begin()+1);
    				tempSet.erase(tempSet.begin(), tempSet.begin()+1);
    			}    				
    		}
    	}
    }
    return counter;
}


int main(){
	string s;
	int k;
	getline(cin, s);
	cin>>k;

	cout<<part1(s,k);
}