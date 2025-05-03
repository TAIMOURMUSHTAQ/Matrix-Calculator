#include <iostream>
using namespace std;
void Add(int A[20][20], int B[20][20], int r, int c);//Addition function declaration
void Subtract(int A[20][20], int B[20][20], int r, int c);//Subtraction function declaration
void Multiply(int A[20][20], int B[20][20], int r1, int c1,int r2,int c2);//Multiplication function declaration
void Transpose(int A[20][20], int B[20][20], int r1, int c1,int r2,int c2);//Transpose function declaration
void PrintMatrixA(int A[20][20],int r1,int c1);//Print function declaration
void PrintMatrixB(int B[20][20],int r2,int c2);//Print function declaration
int main() {
    char operation, choice;
 	int A[20][20], B[20][20], Sum[20][20] = {0}, Diff[20][20] = {0}, Prod[20][20] = {0};
    do {
        cout << "\t\t\t===== Matrix  Calculator ====="<<endl;
        int r1=0,r2=0,c1=0,c2=0;
        cout << "Enter number of rows for first matrix: ";
        cin >> r1;
        cout << "Enter number of columns for first matrix: ";
        cin >> c1;
        cout << "Enter number of rows for second matrix: ";
        cin >> r2;
        cout << "Enter number of columns for second matrix: ";
        cin >> c2;
        
        // Input 1st matrix
        cout << "\nEnter elements of 1st matrix:\n";
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++) {
                cout << "Enter element a" << i + 1 << j + 1 << ": ";
                cin >> A[i][j];
            }

        // Input 2nd matrix
        cout << "\nEnter elements of 2nd matrix:\n";
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++) {
                cout << "Enter element b" << i + 1 << j + 1 << ": ";
                cin >> B[i][j];
            }

		cout<<"\n\nEntered matrices are:"<<endl;
		PrintMatrixA(A,r1,c1);
		PrintMatrixB(B,r2,c2);   
        cout << "\nChoose operation: + (Add), - (Subtract), * (Multiply) t(Transpose): ";
        cin >> operation;

        switch (operation) {
            case '+': // Addition
            if (r1 != r2 || c1 != c2) {
    			cout << "Addition/Subtraction not possible: Matrix dimensions don't match.\n";
    			break;
			}
                Add(A,B,r1,c1);
                break;

            case '-': // Subtraction
            if (r1 != r2 || c1 != c2) {
    			cout << "Addition/Subtraction not possible: Matrix dimensions don't match.\n";
    			break;
			}
                Subtract(A,B,r1,c1);
                break;

            case '*': // Multiplication
               Multiply(A,B,r1,c1,r2,c2);
                break;
            case 't': // Transpose
            case 'T':
               Transpose(A,B,r1,c1,r2,c2);
                break;    

            default:
                cout << "Invalid operation selected.\n";
        }

        cout << "\nPress Y to continue or N to exit: ";
        cin >> choice;

    } 
	while (choice == 'y' || choice == 'Y');
    cout<<"Good Bye! See You Soon.....";
    return 0;
}//End of main

//Addition function definition
void Add(int A[20][20], int B[20][20], int r, int c) 
{
    int Sum[20][20] = {0};
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            Sum[i][j] = A[i][j] + B[i][j];

    cout << "\nSum of two matrices:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << Sum[i][j] << "\t";
        cout << "\n";
    }
}

//Subtraction function definition
void Subtract(int A[20][20], int B[20][20], int r, int c)
{
	int Diff[20][20]={0};
	for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        Diff[i][j] = A[i][j] - B[i][j];

                cout << "\nDifference of two matrices:\n";
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++)
                        cout << Diff[i][j] << "\t";
                    cout << "\n";
                }
}

//Multiplication function definition
void Multiply(int A[20][20], int B[20][20], int r1,int c1,int r2, int c2)
{
	int Prod[20][20]={0};
	 if(c1==r2)//Loop to check whether the multiplication is possible or not
				{
				for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c2; j++)
                        for (int k = 0; k < c1; k++)
                            Prod[i][j] += A[i][k] * B[k][j];

                cout << "\nProduct of two matrices:\n";
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++)
                        cout << Prod[i][j] << "\t";
                    cout << "\n";
                }
				}
				else if(c1>r2){
					cout<<"The columns of first matrix are greater than the rows of second matrix so \"Multiplication\" is not possible ";
				}
				else{
					cout<<"The rows of first matrix are greater than the columns of second matrix so \"Multiplication \" is not possible ";
				}
	}
	
//Transpose function definition
void Transpose(int A[20][20], int B[20][20], int r1, int c1,int r2,int c2){
	cout<<"Which matrix's transpose do you want (A or B)? ";
	char ch;
	cin>>ch;
	if(ch=='A' || ch=='a'){
		cout<<"The Tranpose of Matrix A is: \n";
                    for(int j=0; j<c1 ;j++) {
          for(int i=0; i<r1; i++) {
              cout<<A[i][j];
              cout<<"\t";
          }
          cout<<endl;}
                    
                }
	else if(ch=='B' || ch=='b'){
		cout<<"The Tranpose of Matrix B is: \n";
	for(int j=0; j<c2 ;j++) {
          for(int i=0; i<r2; i++) {
              cout<<B[i][j];
              cout<<"\t";
          }
          cout<<endl;}
}	
}

//Print functions definition
void PrintMatrixA(int A[20][20],int r1,int c1){
	cout<<"\nMatrix A"<<endl;
		 // Display 1st matrix
        for (int i = 0; i < r1; i++){
		for (int j = 0; j < c1; j++) {
			cout<<A[i][j];
			cout<<"\t";
		}
    	cout<<"\n";
            }
}
void PrintMatrixB(int B[20][20],int r2,int c2){
	cout<<"\n\nMatrix B"<<endl;
		 // Display 2nd matrix
        for (int i = 0; i < r2; i++)
            {for (int j = 0; j < c2; j++) {
			cout<<B[i][j];
			cout<<"\t";
            }
            cout<<"\n";
			}
}