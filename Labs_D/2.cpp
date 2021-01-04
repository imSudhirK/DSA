#include <iostream>
#include <cstdlib>
#include<string>
#include<queue>
#include <ctype.h> 
#include <stdio.h>

using namespace std;

class Course{
public:
	char code[6];       //course name code 
	int slot;          // its slot 
	double maxReg;     // maximum registration 
	double nsr;        //number of students registered;
	queue<string> rsl;   //regitered students

	
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
public:
	char roll[9];        //roll number of student 9 char;
	int nrc ;           //number of registerd courses;
	queue<string> rcl;  //registered course list;

	Student(string r){
		for(int i=0; i<9; i++)
			roll[i] = r[i];
	}

	void pS(){
		printf("%s\n", roll );
	}
};


/*
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

*/



int main(){
	int nc;             //number of courses 
	double ns;  //number of students
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



	for(int i=0; i<nop; i+=1){
		char c[1];
		scanf("%1s", c);
		if(c[0]== 'R'){
			char st1[9], cc[6];
			scanf("%9s%6s", st1, cc);

			for(int i=0; i<ns; i+=1){
				string rl;
				for(int j=0; j<9; j++){
					rl += sList[i].roll[j];
				}
				if(rl== st1){
					if(sList[i].rcl.empty()){
						for(int k=0; k<nc; k++){
							string cl;
							for(int l=0; l<9; l++){
								cl += cList[k].code[l];
							}
							if(cl == cc){
								if(cList[k].nsr <cList[k].maxReg){
									printf("%s\n", "success");
									sList[i].rcl.push(cc);
									cList[k].rsl.push(st1);
								}
								else if(cList[k].nsr >=cList[k].maxReg){
									printf("%s\n", "fail");
								}
							}
						}
					}
					else{
						queue<string> rcl2;
						rcl2 = sList[i].rcl;
						bool b = false;
						while(!rcl2.empty()){
							if(rcl2.front() == cc){
								b = true;
								break;
							}
						}
						if(b == true)
							printf("%s\n", "fail" );
						else if(b==false){
							for(int k=0; k<nc; k++){
								string cl;
								for(int l=0; l<9; l++){
									cl += cList[k].code[l];
								}
								if(cl == cc){
									if(cList[k].nsr <cList[k].maxReg){
										printf("%s\n", "success");
										sList[i].rcl.push(cc);
										cList[k].rsl.push(st1);
									}
									else if(cList[k].nsr >=cList[k].maxReg){
										printf("%s\n", "fail");
									}
								}
							}
						}
					}
				}	
			}	
		}

		if(c[0]== 'D'){
			char st1[9], cc[6];
			scanf("%9s%6s", st1, cc);

			for(int i=0; i<ns; i+=1){
				string rl;
				for(int j=0; j<9; j++){
					rl += sList[i].roll[j];
				}
				if(rl== st1){
					if(sList[i].rcl.empty())
						printf("%s\n", "success");
					else{
						queue<string> rcl2;
						rcl2 = sList[i].rcl;
						bool b = false;
						while(!rcl2.empty()){
							if(rcl2.front() == cc){
								b = true;
								break;
							}
						}
						if(b == true)
							printf("%s\n", "fail" );
						else if(b==false){
							printf("%s\n", "success");
							sList[i].rcl.push(cc);
						}
					}
				}	
			}
		}
	}

	//cList[1].pC();
	//sList[1].pS();	

}
