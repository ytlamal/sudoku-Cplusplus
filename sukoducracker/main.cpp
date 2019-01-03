/*
 * main.cpp
 *
 *  Created on: 2019¦~1¤ë3¤é
 *      Author: User
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

 int sudoku[9][9];
     int input[9][9]{
    		 {0,4,0,0,2,6,0,7,9},
    		 {2,1,0,0,0,5,3,0,8},
    		 {0,0,0,0,8,0,6,0,0},
    		 {0,0,0,0,0,9,8,0,3},
    		 {9,6,5,0,0,0,4,1,7},
    		 {1,0,3,5,0,0,0,0,0},
    		 {0,0,2,0,4,0,0,0,0},
    		 {8,0,1,6,0,0,0,9,4},
    		 {7,9,0,8,1,0,0,3,0},
//    	 {1,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
//		 {0,0,0,0,0,0,0,0,0},
    };
     void print(int input[9][9]){
	 for(int i=0;i<9;i++){
		 for(int j=0;j<9;j++){
			 cout<<input[i][j]<<" ";
		 }
		 cout<<endl;
	 }
 }
     int check[] {1,2,3,4,5,6,7,8,9};
     bool change[9][9]{
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        		 {0,0,0,0,0,0,0,0,0},
        };
 void readinputchange(){
	 for(int i=0;i<9;i++) {
	 	for(int j=0;j<9;j++) {
	 		if(input[i][j]!=0){
	 			change[i][j]=true;
	 		}
	 	}
	 }
 }
 void copysudoku(int input[9][9],int target[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			target[i][j]=input[i][j];
		}
	}
 }
 void readsudoku() {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				//if(input[i][j]!=null) {
				if( input[i][j]<10) {
				sudoku[i][j]=input[i][j];
				//cout<<sudoku[i][j]<<endl;
				}
			//}
			else{
				sudoku[i][j]=0;
			}
				}
		}
	}
	 bool checksudoku(int sudokut[9][9]) {
		//by line
		for(int i=0;i<9;i++) {
			int repeat [] {0,0,0,0,0,0,0,0,0};
 			for(int j=0;j<9;j++) {
				if(sudokut[i][j]<10&&sudokut[i][j]>0) {
					repeat[sudokut[i][j]-1]++;
					if(repeat[sudokut[i][j]-1]>=2) {
						//cout<<i<<"  "<<j <<"was not pass"<<endl;
						return false;
					}
				}
			}
		}
		for(int i=0;i<9;i++) {
					int repeat [] {0,0,0,0,0,0,0,0,0};
		 			for(int j=0;j<9;j++) {
						if(sudokut[j][i]<10&&sudokut[j][i]>0) {

							repeat[sudokut[j][i]-1]++;
							if(repeat[sudokut[j][i]-1]>=2) {
								cout<<i<<"  "<<j <<"was not pass"<<endl;
								return false;
							}
						}
					}
				}
		//by square
		for(int i=0;i<9;i+=3) {
			for(int j=0;j<9;j+=3) {
				int repeat[] {0,0,0,0,0,0,0,0,0};
				for(int k=0;k<3;k++) {
					for(int z=0;z<3;z++) {
						if(sudokut[i+k][j+z]<10&&sudokut[i+k][j+z]>0) {
							repeat[sudokut[i+k][j+z]-1]++;
							if(repeat[sudokut[i+k][j+z]-1]>=2) {

								cout<<"i="<<i<<",j="<<j<<",k="<<k<<"z="<<z<<"wrong="<<i+k<<j+z<<endl;
								return false;
							}
						}
					}
				}
			}
		}
		return true ;

	}
	 bool checkfinish(int sudokutemp[9][9]){
		 for (int i=0;i<9;i++){
			 for(int j=0;j<9;j++){
				 if(sudokutemp[i][j]==0){
					 return false;
				 }
			 }
		 }
		 return true;
	 }
	bool crack(int temp[9][9]){
		int tempinput[9][9];
		copysudoku(temp,tempinput);
		//base case
		if(checkfinish(tempinput)&&checksudoku(tempinput)){
			copysudoku(tempinput,sudoku);
			return true;
		}
		//recursion part
		for (int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(tempinput[i][j]==0){
						for(int k=1;k<10;k++){

							tempinput[i][j]=k;

							 if(checksudoku(tempinput)){
								 print(tempinput);
								 crack(tempinput);
							 }
						 }
						}
					 }
				 }
		return false;
	}
	int main(){
		readsudoku();
		if( checksudoku(sudoku)){
			cout<<"good"<<endl;
			crack(sudoku);
			print(sudoku);

		}else{
			cout<<"bad"<<endl;
		}


}
