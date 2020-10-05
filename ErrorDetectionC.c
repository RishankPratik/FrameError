#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
int main()
{
char a[MAX],b[MAX];
int sockfd,len,n,j,i,key;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else{
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(len));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(PORT);
len=sizeof(servaddr);
const char *ch[1];
for(j=0;j<1;j++)
{
printf("****This is an error detection program****");
printf("Enter your choice: ");
printf("\n1. Checksum\n2. Cyclic Redundancy Check\n3. Parity(1-bit)\n");
scanf("%c",ch);
sendto(sockfd,ch,sizeof(ch),0,(SA *)&servaddr,len);
sscanf(ch,"%d", &key);
if(key==1)
{
printf("Enter first binary string\n");
scanf("%s",&a);
printf("Enter second binary string\n");
scanf("%s",&b);
sendto(sockfd,a,sizeof(a),0,(SA *)&servaddr,len);
sendto(sockfd,b,sizeof(b),0,(SA *)&servaddr,len);
bzero(a,sizeof(a));
bzero(b,sizeof(b));
}
else if(key==2)
{
int keylen,msglen;
char input[100], key[30],temp[30],quot[100],rem[30],key1[30];
printf("\nEnter Data: ");
scanf("%s",input);
printf("\nEnter Key: ");
scanf("%s",key);
sendto(sockfd,input,sizeof(input),0,(SA *)&servaddr,len);
sendto(sockfd,key,sizeof(key),0,(SA *)&servaddr,len);
bzero(input,sizeof(input));
bzero(key,sizeof(key));
}
else if(key==3)
{
char b[50];
printf("\nEnter Coded BCD: ");
scanf("%s",b);
sendto(sockfd,b,sizeof(b),0,(SA *)&servaddr,len);
bzero(b,sizeof(b));

}
else{
printf("choice other than 1, 2 and 3 not accepted");}
}


close(sockfd);
}
}
