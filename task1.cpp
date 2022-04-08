#include<iostream>
using namespace std;
template<class T>
class twoDarray{
    int row_size,column_size;
    T **array;
public:
    twoDarray(){}
    twoDarray(int row_size,int column_size);
    void set_attributes();
    int getrowsize();
    int getcolumnsize();
    void set_matrix();
    void input_matrix();
    void display();
    void set_specific_element(int row_size,int column_size,T number);
    T get_specific_element(int row_size,int column_size);
    twoDarray operator+(const twoDarray &obj){
        twoDarray temp(this->row_size,this->column_size);
        for(int i=0;i<this->row_size;i++){
            for(int j=0;j<this->column_size;j++)
                {
                    temp.array[i][j]=array[i][j]+obj.array[i][j];
                    cout << "temp [" << i + 1 << "]["<< j + 1 << "] : " << temp.array[i][j] << endl;
                }
        }
        return temp;
    }
    twoDarray operator-(const twoDarray &obj){
        twoDarray temp(this->row_size,this->column_size);
        for(int i=0;i<this->row_size;i++){
            for(int j=0;j<this->column_size;j++)
                temp.array[i][j]=array[i][j]-obj.array[i][j];
        }
        return temp;
    }
    twoDarray operator*(const twoDarray &obj){
        twoDarray temp(this->row_size,this->column_size);
        for(int i=0;i<this->row_size;i++){
            for(int j=0;j<this->column_size;j++)
                temp.array[i][j]=array[i][j]*obj.array[i][j];
        }
        return temp;
    }
    twoDarray operator+(int value){
        twoDarray temp(this->row_size,this->column_size);
        for(int i=0;i<this->row_size;i++){
            for(int j=0;j<this->column_size;j++)
                temp.array[i][j]=array[i][j]+value;
        }
        return temp;
    }~twoDarray();
};
template<class T>
twoDarray<T> ::twoDarray(int row_size,int column_size){
    this->row_size=row_size;
    this->column_size=column_size;
    set_matrix();
}
template<class T>
void twoDarray<T>::set_attributes(){
    cout<<"enter row size: ";
    cin>>row_size;
    cout<<"enter column size: ";
    cin>>column_size;
    set_matrix();
}
template<class T>
int twoDarray<T>::getrowsize(){return row_size;}
template<class T>
int twoDarray<T>::getcolumnsize(){return column_size;}
template<class T>
void twoDarray<T>:: set_matrix(){
    array=new T*[row_size];
    for(int i=0;i<row_size;i++)
        array[i]=new T[column_size]{0};
}
template<class T>
void twoDarray<T>::input_matrix(){
    for(int i=0; i<row_size; i++){
        cout<<"enter data of row "<<i+1<<"\n";
        for(int j=0; j<column_size; j++){
            cout<<"enter [ "<<i+1<<" ][ "<<j+1<<" ] : ";
            cin>>array[i][j];
        }
    }
}
template<class T>
    void twoDarray<T>::display(){
        for(int i=0; i<row_size; i++){
            for(int j=0; j<column_size; j++)
                cout<<"[ "<<i+1<<" ][ "<<j+1<<" ] :" <<array[i][j]<<endl;
        }
    }
    template<class T>
void twoDarray<T>::set_specific_element(int row_size,int column_size,T number){
       array[row_size][column_size]=number;
}
template<class T>
T twoDarray<T>:: get_specific_element(int row_size,int column_size){return array[row_size][column_size]; }
template<class T>
twoDarray<T>::~twoDarray(){
    delete[] array;
    array=0;
}
int  main(){
    twoDarray<float> obj1;
    twoDarray<float> obj2(3,2);
    twoDarray<float> obj3;
    obj1.set_attributes();
    cout<<"enter data for object 1: "<<endl;
    obj1.input_matrix();
    cout<<"enter data for object 2: "<<endl;
    obj2.input_matrix();
    char word;
	do{
		cout << " enter 1 for input matrix\n enter 2 for display matrix\n press 3 for setting a specfic element using single number as index\n press 4 for getting a specific element using single number as index\n press 5 for adding a matrix \n press 6 for subtracting matrix\n press 7 for adding a constant to matrix \n press 8 for multiplying matrix \n press 9 for exit" << endl;
		int n;
		cin >> n;
		if (n == 1){
            cout<<"input matrix for object 1: "<<endl;
            obj1.input_matrix();
            cout<<"input matrix for object 2: "<<endl;
            obj2.input_matrix();
        }else if (n == 2){
            cout<<"display matrix for object 1: "<<endl;
            obj1.display();
            cout<<"display matrix for object 2: "<<endl;
            obj2.display();
        }
		else if (n == 3) {
			int row_index, column_index, number;
            cout << "enter row index :";
			cin >> row_index;
            while(row_index>obj1.getrowsize()&&row_index>0){
                cout<<"retenter row index: ";
                cin>>row_index;
            }
			cout << "enter column index :";
			cin >> column_index;
            while(column_index>obj1.getcolumnsize()&&column_index>0){
                cout<<"reenter column index: ";
                cin>>column_index;
            }
		    cout << "enter number :";
		    cin >> number;
    	    obj1.set_specific_element(row_index, column_index, number);
        }
		else if (n == 4){
			int row_index, column_index, number;
            cout << "enter row index :";
			cin >> row_index;
            while(row_index>obj1.getrowsize()&&row_index>0){
                cout<<"retenter row index: ";
                cin>>row_index;
            }
			cout << "enter column index :";
			cin >> column_index;
            while(column_index>obj1.getcolumnsize()&&column_index>0){
                cout<<"reenter column index: ";
                cin>>column_index;
            }
        	cout << "number of row : " << row_index << " and column : " << column_index <<" : "<< obj1.get_specific_element(row_index, column_index)<<endl;
		}
		else if (n == 5){
			obj3 = obj1 + obj2;
            obj3.display();
		}
		else if (n == 6){
			obj3 = obj1 - obj2;
            obj3.display();
		}
		else if (n == 7){
			obj3 = obj1 + 5;
            obj3.display();
        }
		else if (n == 8){
			obj3 = obj1*obj2;
            obj3.display();
        }
		else
			return 0;
		cout << "wanna see menu again (enter y for yes): ";
		cin >> word;
	} while (word != 'Y');
    return 0;
}
