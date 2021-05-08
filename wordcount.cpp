#include<stdio.h>
#include<string.h>
int getChar(FILE *fp);  //计算字符数量
int getWord(FILE *fp);  //计算单词数量
int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
    	//读文件 
		fp = fopen(argv[2],"r");
		
		if(fp == NULL){
			printf("错误！找不到文件\n",argv[2]);
		} 
			////-c 统计字符数 
		    if(!strcmp(argv[1],"-c")){ 
		        number = getChar(fp);
		     	printf("字符数为%d\n",number);
		    }
		    ////-w 统计单词数 
		    else if(!strcmp(argv[1],"-w")){ 
			    number = getWord(fp);
			    printf("单词数为%d\n",number); 
		   }
	}
	
}
//统计文件字符数 
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch=='\n') || (ch==' ') || (ch=='\t')){////字母，空格，\t，\n都算字符 
			number++;
		}
	}
	
	return number;
}

//统计文件单词数 
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
        else if(flag == 0 && (ch != ' ' && ch != '\''&& ch !=','))  ///排除' ','\tn',',' 
        {
            number++;
            flag = 1;
        }
    }
    
    return number;
}



