#include<stdio.h>
#include<string.h>
int getChar(FILE *fp);  //�����ַ�����
int getWord(FILE *fp);  //���㵥������
int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
    	//���ļ� 
		fp = fopen(argv[2],"r");
		
		if(fp == NULL){
			printf("�����Ҳ����ļ�\n",argv[2]);
		} 
			////-c ͳ���ַ��� 
		    if(!strcmp(argv[1],"-c")){ 
		        number = getChar(fp);
		     	printf("�ַ���Ϊ%d\n",number);
		    }
		    ////-w ͳ�Ƶ����� 
		    else if(!strcmp(argv[1],"-w")){ 
			    number = getWord(fp);
			    printf("������Ϊ%d\n",number); 
		   }
	}
	
}
//ͳ���ļ��ַ��� 
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch=='\n') || (ch==' ') || (ch=='\t')){////��ĸ���ո�\t��\n�����ַ� 
			number++;
		}
	}
	
	return number;
}

//ͳ���ļ������� 
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(feof(fp)==0)
    {
       ch = fgetc(fp);
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ){
             flag = 0;
        }
        else if(flag == 0 && (ch != ' ' && ch != '\''&& ch !=','))  ///�ų�' ','\tn',',' 
        {
            number++;
            flag = 1;
        }
    }
    
    return number;
}



