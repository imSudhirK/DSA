#include <iostream>
#include <cstdlib>
#include<string>
#include<queue>
#include <ctype.h> 
#include <stdio.h>

using namespace std;

class Course{
private:
	char code[6];       //course name code 
	int slot;          // its slot 
	double maxReg;     // maximum registration 
	double nsr;        //number of students registered;

public:	
	Course(){
		nsr =0;
	}

	Course(string cc, int cs, double cmr){
		for(int i=0; i<6; i++)
			code[i] = cc[i];
		slot = cs;
		maxReg = cmr;
	}

	void pC(){
		printf("%s%s%d%s%lf%s%lf\n", code," ", slot," ", maxReg," ", nsr);
	}

};




class Student{
private:
	char roll[9];        //roll number of student 9 char;
	int nrc ;           //number of registerd courses;
public:
	Student(string r){
		for(int i=0; i<9; i++)
			roll[i] = r[i];
	}

	void pS(){
		printf("%s\n", roll );
	}
};



class OPS{
private:
	char com;         //operation command char 
	char stRoll1[9], stRoll2[9];   //student roll number 
	char courseCode1[6], courseCode2[6];        //course name

public:
	OPS(char c){
		com =c;
		if(c== 'R' || c=='D'){
			char st1[9], cc[6];
			scanf("%9s%6s", st1, cc);
			for(int i=0; i<9; i++){
				stRoll1[i] = st1[1];
			}
			for(int i=0; i<6; i++){
				courseCode1[i] = cc[1];
			}
		}
		else if(com=='P'){
			
			queue<char>q;

			while(true){
				char c2[1];
				scanf("%1s", c2);
				if(c2[0] == '\n') break;
				else if(!isspace(c2[0]))
					q.push(c2[0]);
			}

			int sq = q.size();
			if(sq== 6){
				for(int i=0; i<6; i++){
					courseCode1[i] = q.front();
					q.pop();
				}
			}
			else if(sq==9){
				for(int i=0; i<9; i++){
					stRoll1[i] = q.front();
					q.pop();
				}
			}
			else if(sq==12){
				for(int i=0; i<6; i++){
					courseCode1[i] = q.front();
					q.pop();
				}
				for(int i=0; i<6; i++){
					courseCode2[i] = q.front();
					q.pop();
				}
			}
			else if(sq==18){
				for(int i=0; i<18; i++){
					stRoll1[i] = q.front();
					q.pop();
				}
				for(int i=0; i<6; i++){
					stRoll2[i] = q.front();
					q.pop();
				}
			}			
		}
	}

};





int main(){
	int nc;             //number of courses 
	double ns;;  //number of students
	long double nop;  //number of operations 
	scanf("%d%lf%Lf", &nc, &ns, &nop);

   
    Course* cList =(Course*)malloc(sizeof(Course)* nc);
	
	char cCode[6];
	int slotN;
	double max_Reg;

	for(int i=0; i<nc; i++){
		scanf("%6s%d%lf", cCode, &slotN, &max_Reg);
		cList[i] = Course( cCode, slotN, max_Reg);
	}

	Student* sList =(Student*)malloc(sizeof(Student)*ns);
	char sRoll[9];

	for(int i=0; i<ns; i+=1){
		scanf("%9s", sRoll);
		sList[i] = Student(sRoll);
	}

	OPS* opList =(OPS*)malloc(sizeof(OPS)*nop);
	

	for(int i=0; i<nop; i+=1){
		char c[1];
		scanf("%1s", c);
		opList[i] = OPS(c[0]);
	}

	//cList[1].pC();
	//sList[1].pS();	

}
