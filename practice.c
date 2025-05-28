#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[16];
    int grades[100];
    int cnt;
    float avg;
};

void ReadData(struct Student s[],int n,FILE * infile);
float calcAvg(struct Student s);
void selectionSort(struct Student s[],int n);
int binarySearch(struct Student s[],int n,int target);

int main(){
    FILE * infile;
    infile=fopen("data.txt","r");
    if(infile==NULL){
        printf("Error");
    return 1;
    }

    int n;
    fscanf(infile,"%d",&n);
    struct Student s[n];
    readData(s,n,infile);
    selectionSort(s,n);

    int target;
    scanf("%d",&target);
    int key=binarySearch(s,n,target);
    for(int i=key;i<n;i++){
        printf("%s %f",s[i].name,s[i].avg);
    }
return 0;
    
}

float calcAvg(struct Student s){
    int sum=0;
    for(int i=0;i<s.cnt;i++){
         sum+=s.grades[i];
    }
    return (float) sum/s.cnt;
}



void ReadData(struct Student s[],int n,FILE * infile){
    int temp;
    for(int i=0;i<n;i++){
        int j=0;
        s[i].cnt=0;
        fscanf(infile,"%s",s[i].name);
        while(1){
            fscanf(infile,"%d",&temp);
            if(temp==999)
            break;
            s[i].grades[j]=temp;
            s[i].cnt++;
            j++;
        }
        s[i].avg=calcAvg(s[i]);
    }
}

void selectionSort(struct Student s[], int n){
    for(int i=0;i<n;i++){
        int minI=i;
        for(int j=i+1;j<n;j++){
        if(s[j].avg<s[minI].avg)
        minI=j;
    }
    struct Student temp=s[i];
    s[i]=s[minI];
    s[minI]=temp;
}
}

int binarySearch(struct Student s[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(s[mid].avg>=target)
        high=mid-1;
        else
        low=mid+1;
    }
}
