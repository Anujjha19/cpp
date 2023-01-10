#include<iostream>
using namespace std;
/* int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
        while(j<=i){
          cout<< "*";
j=j+1;
        }
cout<<endl;
i=i+1;
    }
} */
/* 
int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
        while(j<=i){
          cout<< i;
j=j+1;
        }
cout<<endl;
i=i+1;
    }
}
 */
/* int main (){
    int n;
    cin>> n;
    int i=1;
    int count=1;
    while(i<=n){
        int j=1;
        while(j<=i){
          cout<< count <<" ";
          count=count+1;
j=j+1;
        }
cout<<endl;
i=i+1;
    }
} */

/* int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
         int value=i;
        while(j<=i){
          cout<< value;
          value=value+1;
j=j+1;
        }
cout<<endl;
i=i+1;
    }
} */

/* int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=i;
        while(j < i*2){
          cout<< j;
j=j+1;
        }
cout<<endl;
i=i+1;
    }
}
 */
/* 
int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
        while(j<=i){
          cout<< i-j+1 ;
j=j+1;
        }
cout<<endl;
i=i+1;
    }
}
 */


/* int main (){
    int n;
    cin>> n;
    int i=1;
    char ch= 97;
    while(i<=n){
        int j=1;
        while(j<=n){
          cout<< ch;
j=j+1;
ch=ch+1;
        }
cout<<endl;
i=i+1;   
    }
}
 *//* 
int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
        while(j<=n){
          char ch='A' + i - 1; 
          cout<< ch;
j=j+1;
        }
cout<<endl;
i=i+1;   
    }
} */
/* 
int main (){
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
        while(j<=n){
          char ch='A' + j - 1; 
          cout<< ch;
j=j+1;
        }
cout<<endl;
i=i+1;   
    }
} */
/* 
 int main (){
    int n;
    cin>> n;
    int i=1;
    char ch= 'A';
    while(i<=n){
        int j=1;
        while(j<=n){
          cout<< ch;
j=j+1;
ch=ch+1;
        }
cout<<endl;
i=i+1;   
    }
} */



/* 
 int main (){
    /*
      i + j - 1 = 1 

  
add (A - 1 )both side,
i+j-1 + A - 1 = 1+ A -1 

A + i + j -2 = A 
*/
/*
char
    int n;
    cin>> n;
    int i=1;
    
    while(i<=n){
        int j=1;
        while(j<=n){
          cout<<(char)( 'A' + i + j - 2);
j=j+1;

        }
cout<<endl;
i=i+1;   
    }
}
 *//* 
int main(){
    int n;
    cin>>n;
    int row=1;
    while( row <=n){
        int col=1;
        while(col<= row){
            char ch=('A' + row -1);
            cout<< ch;
            col = col +1;
        }
        cout<<endl;
        row= row+1;
    }
} */

/* int main(){
    int n;
    cin>>n;
    int row=1;   
         char ch='A';

    while( row <=n){
        int col=1;
        while(col<= row){
            cout<< ch;
            col = col +1;
            ch=ch+1;
        }
        cout<<endl;
        row= row+1;
    }
} */
/* int main(){
    int n;
    cin>>n;
    int row=1;   
        

    while( row <=n){
        int col=1;
        while(col<= row){ 
            char ch=('A' + row + col -2);
            cout<< ch;
            col = col +1;
           // ch=ch+1;
        }
        cout<<endl;
        row= row+1;
    }

 /* 
 int main(){
    int n;
    cin>>n;
    int row=1;   
        

    while( row <=n){
        int col=1;
        while(col<= row){ 
           
            cout<< (char)( 'A' + row + col -2);
            col = col +1;
           // ch=ch+1;
        }
        cout<<endl;
        row= row+1;
    }
}
 */
 /* int main(){
    int n;
    cin>>n;
    int row=1;   
        

    while( row <=n){
        int col=1;
        char start = 'A' +n - row;
        while(col<= row){ 
           
            cout<< start ;
            col = col +1;
            start=start+1;
        }
        cout<<endl;
        row= row+1;
    }
} */

 /* int main(){
    int n;
    cin>>n;
    int row=1;   

    while(row <=n){
 //print space
 int space=n-row;
 while(space ){
    cout<< " ";
    space= space-1;
 }
 int col=1;
 while(col<=row){
    cout<<"*";
    col=col+1;
 }
row= row+1;
cout<<endl;

        // stars print krlo
    }
    return 0;

} */
/* int main(){
    int n;
    cin>>n;
    int i=1;   
int j=1, k=1;

    while(k<i){
 //print k
 
 while(k <i){
    cout<< " ";
    k= k+1;
 }
 
 while(j<=n-i+1){
    cout<<"*";
    j=j+1;
 }
i= i+1;
cout<<endl;

        // stars print krlo
    }
    return 0;

} */


