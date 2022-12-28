
#include <stdio.h>  
#include <WinSock.h>  

#include <Windows.h>  
#include<mysql.h>

#include<string.h>



#pragma comment(lib,"wsock32.lib") 
#pragma comment(lib,"libmysql.lib")

MYSQL mysql; 
MYSQL_FIELD* fd;  
char field[32][32];  
MYSQL_RES* res; 
MYSQL_ROW column; 
char query[150]; 

void insert(char* name, int age);
void select(char* name);
void selectall(char *name);
void delect1(char* name);
void delect2(int age);
void update(char* oname, int oage, char* name, int age);

int connect() {
		
		mysql_init(&mysql);  
		const char host[] = "localhost";
		const char user[] = "Kesivn";
		const char psw[] = "Dcy706803";
		const char table[] = "huawei";
		const int port = 3306;
		if (!(mysql_real_connect(&mysql, host, user, psw, table, port, NULL, 0)))  
		{
			printf("Error connecting to database:%s\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("Connected...\n");
			return true;
		}
}

int main() {
	return 0;
}

void insert(char* name, int age) {
	sprintf(query, "insert into user(UserName,UserPass,ConnectionNum,UseFor) values('%s','%s',%d,%d)", "Kesivn", "Dcy706803", name, age);
	if (mysql_query(&mysql, query))        
	{
		printf("failed (%s)\n", mysql_error(&mysql));
	}
	else
	{
		printf("success\n");
	}
}
void select(char* name) {
	if (mysql_query(&mysql, name)) {
		printf("error\n");
	}
	else {
		mysql_fetch_row(res);
	}
}
void selectall(char *name) {
	if (mysql_query(&mysql, name)) {
		printf("error\n");
	}
	else {
		mysql_store_result(&mysql);
	}
	mysql_store_result(&mysql);
}
void delect1(char* name) {
	gets_s(query);  //�����ֶ�����sql���  
	if (mysql_query(&mysql, query))        
	{
		printf("failed (%s)\n", mysql_error(&mysql));
	}
	else
	{
		printf("success\n");
	}
}
void delect2(int age) {
	sprintf(query, "delete from user where UserName='%d'", age);
	mysql_query(&mysql, query);

}
void update(char* oname, int oage, char* name, int age) {
	delect1(oname);
	insert(name, age);
}


void innerjoin(char* name, char* suject, int score) {
	sprintf(query, "alter table huawei add records");
	mysql_query(&mysql, query);
	sprintf(query, "alter table huawei add foreign key(name) references records(cid);");
	mysql_query(&mysql, query);

}
void leftjoin(char* name, char* suject, int score) {
	sprintf(query, "alter table huawei add records");
	mysql_query(&mysql, query);
	sprintf(query, "alter table huawei add foreign key(name) references records(cid);");
	mysql_query(&mysql, query);
}

	
