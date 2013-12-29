#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>

using namespace std;

//taking input
int test;
int totalCount;
int overfit=0;
int factor=5000;
int totalDistCount=1;

class String
{
	private:
		struct node
		{
			int value;
			node * alpha[42];		
			// 0-25 characters,
			// 26-35 0-9,
			// 36--- @
			// 37--- ?
			// 38--- !
			// 39--- _
			//40---  $
			//41 --- %
		};
		node * root;
		
	
	public:

		String()
		{
			root=(node *)malloc(sizeof(node));
			root->value=0;
			for(int i=0;i<42;i++)
			{
				root->alpha[i]=NULL;
			}
		}	
		
		int addString(char * str)
		{
			int k=0,j=strlen(str);
			node * p=root;
			while(k < j)	
			{
				if(str[k] >= 97 && str[k] <= 122)
				{
					if(p->alpha[str[k]-'a']==NULL)
					{
						p->alpha[str[k]-'a']=(node *)malloc(sizeof(node));
						p->alpha[str[k]-'a']->value=0;
						for(int i=0;i<42;i++)
							p->alpha[str[k]-'a']->alpha[i]=NULL;
					}
					p=p->alpha[str[k]-'a'];
					k++;	
				}
				else if(str[k] >= 65 && str[k] <= 90)
				{
					if(p->alpha[str[k]-'A']==NULL)
					{
						p->alpha[str[k]-'A']=(node *)malloc(sizeof(node));
						p->alpha[str[k]-'A']->value=0;
						for(int i=0;i<42;i++)
							p->alpha[str[k]-'A']->alpha[i]=NULL;
					}
					p=p->alpha[str[k]-'A'];
					k++;		
				}
				else if(str[k] >=48 && str[k]<=57)
				{
					if(p->alpha[str[k]-22]==NULL)         // 26-48=-22
					{
						p->alpha[str[k]-22]=(node *)malloc(sizeof(node));
						p->alpha[str[k]-22]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[str[k]-22]->alpha[i]=NULL;
					}
					p=p->alpha[str[k]-22];
					k++;		
				}
			//	36--- @
			// 37--- ?
			// 38--- !
			// 39--- _
			//40---  $
			//41 --- %
				else if(str[k]=='@')
				{
					if(p->alpha[36]==NULL)  
					{
						p->alpha[36]=(node *)malloc(sizeof(node));
						p->alpha[36]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[36]->alpha[i]=NULL;
					}
					p=p->alpha[36];
					k++;			
				}
				else if(str[k]=='?')
				{
					if(p->alpha[37]==NULL)  
					{
						p->alpha[37]=(node *)malloc(sizeof(node));
						p->alpha[37]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[37]->alpha[i]=NULL;
					}
					p=p->alpha[37];
					k++;				
					
				}
				else if(str[k]=='!')
				{
					if(p->alpha[38]==NULL)  
					{
						p->alpha[38]=(node *)malloc(sizeof(node));
						p->alpha[38]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[38]->alpha[i]=NULL;
					}
					p=p->alpha[38];
					k++;				
				}
				else if(str[k]=='_')
				{
					if(p->alpha[39]==NULL)  
					{
						p->alpha[39]=(node *)malloc(sizeof(node));
						p->alpha[39]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[39]->alpha[i]=NULL;
					}
					p=p->alpha[39];
					k++;				
				}
				else if(str[k]=='$')
				{
					if(p->alpha[40]==NULL)  
					{
						p->alpha[40]=(node *)malloc(sizeof(node));
						p->alpha[40]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[40]->alpha[i]=NULL;
					}
					p=p->alpha[40];
					k++;				
				}
				else if(str[k]=='%')
				{
					if(p->alpha[41]==NULL)  
					{
						p->alpha[41]=(node *)malloc(sizeof(node));
						p->alpha[41]->value=0;
						for(int i=0;i<42;i++)
							p->alpha[41]->alpha[i]=NULL;
					}
					p=p->alpha[41];
					k++;				
				}
				else
				{
					k++;
				}
			}
				p->value++;
			return p->value;
		}

		int getStringCount(char * str)
		{
			node * p=root;
			int k=0,i=0,n=strlen(str);
			while(i<n)
			{
				if(str[i] >= 97 && str[i] <= 122)
				{
					p=p->alpha[str[i]-'a'];
				}
				else if(str[i] >= 65 && str[i] <= 90)
				{
					p=p->alpha[str[i]-'A'];
				}
				else if(str[i] >=48 && str[i]<=57)
				{
					p=p->alpha[str[i]-22];
				}
			//	36--- @
			// 37--- ?
			// 38--- !
			// 39--- _
			//40---  $
			//41 --- %
				else if(str[i]=='@')
				{
					p=p->alpha[36];
				}
				else if(str[i]=='?')
				{
					p=p->alpha[37];
				}
				else if(str[i]=='!')
				{
					p=p->alpha[38];
				}
				else if(str[i]=='_')
				{
					p=p->alpha[39];
				}
				else if(str[i]=='$')
				{
					p=p->alpha[40];
				}
				else if(str[i]=='%')
				{
					p=p->alpha[41];
				}
				if(p==NULL)
				{
						k=1;
						break;
				}
				i++;		

			}
			if(k==1 || p->value==0)
			{
				return 0;
			}
			else
				return p->value;
		}
		

};


class Primary : String
{
	private:
		int wordCount;      // total no. of words in this category.
		int count;			// total no. of primary messages.
		int distWordCount;  // total no. of distinct words in the category.
	public:
		Primary()
		{
			wordCount=0;
			count=0;
			distWordCount=0;
		}
		
		void read(char * str)
		{
			if(addString(str)==1)
				distWordCount++;	
			wordCount++;
		}
		
		double getStringProbability(char * str)
		{
			if(wordCount>0)
				return (((getStringCount(str)+ overfit)*1.0f)*factor)/(wordCount+totalDistCount*overfit);		// yo
			else
				return 0.0f;
		}
		
		int incCount()
		{
			count++;
		}
		
		double getProbability()
		{
			if(totalCount > 0)
				return (((count + overfit) * 1.0f)*factor)/(totalCount + 3*overfit);
			else
			{
				return 0.0f;
			}
		}		
};

class Social : String
{
	private:
		int wordCount;      // total no. of words in this category.
		int count;			// total no. of primary messages.
		int distWordCount;
	public:
		Social()
		{
			wordCount=0;
			count=0;
			distWordCount=0;
		}
		
		void read(char * str)
		{
			if(addString(str)==1)
				distWordCount++;	
			wordCount++;
		}
		
		double getStringProbability(char * str)
		{
			if(wordCount>0)
				return (((getStringCount(str)+ overfit)*1.0f)*factor)/(wordCount+totalDistCount*overfit);		// yo
			else
				return 0.0f;
		}
		
		int incCount()
		{
			count++;
		}
		
		double getProbability()
		{
			if(totalCount > 0)
				return (((count + overfit) * 1.0f)*factor)/(totalCount + 3*overfit);
			else
			{
				return 0.0f;
			}
		}	
};

class Promotional : String
{
	private:
		int wordCount;      // total no. of words in this category.
		int count;			// total no. of primary messages.
		int distWordCount;
	public:
		Promotional()
		{
			wordCount=0;
			count=0;
			distWordCount=0;
		}
		
		void read(char * str)
		{
			if(addString(str)==1)
				distWordCount++;	
			wordCount++;
		}
		
		double getStringProbability(char * str)
		{
			if(wordCount>0)
			{
				return (((getStringCount(str)+ overfit)*1.0f)*factor)/(wordCount+totalDistCount*overfit);		// wrong
			}
			else
			{
				return 0.0f;
			}
		}
		
		int incCount()
		{
			count++;
		}
		
		double getProbability()
		{
			if(totalCount > 0)
				return (((count + overfit) * 1.0f)*factor)/(totalCount + 3*overfit);
			else
			{
				return 0.0f;						
			}
		}
		
};

class Common : String
{
	private:
		int distWordCount;  // total no. of distinct words in the category.
	public:
		Common()
		{
			distWordCount=0;
		}
		
		void read(char * str)
		{
			if(addString(str)==1)
				distWordCount++;	
		}
		
		int getDistCount()				
		{
			return distWordCount;
		}
};




int main()
{
	char str[5000];
	scanf("%d",&test);
	int cvSet=(int)(0.2*test);							// this is to 20% of data as cross validation set.
	int cvTemp=cvSet;
	totalCount=test-cvSet;
	int testCase=totalCount;
	Primary pi;
	Social so;
	Promotional pr;
	Common co;

	while(testCase)
	{
		scanf("%s",str);
		scanf("%s",str);
		if(strcmp(str,"Primary")==0)
		{
			pi.incCount();
			scanf("%s",str);
			while(strcmp(str,"######"))
			{
				pi.read(str);		
				co.read(str);
				scanf("%s",str);
			}
		}
		else if(strcmp(str,"Social")==0)
		{
			so.incCount();
			scanf("%s",str);
			while(strcmp(str,"######"))
			{
				so.read(str);	
				co.read(str);	
				scanf("%s",str);
			}
		}
		else if(strcmp(str,"Promotional")==0)
		{
			pr.incCount();
			scanf("%s",str);
			while(strcmp(str,"######"))
			{
				pr.read(str);	
				co.read(str);					
				scanf("%s",str);
			}	
		}		
		testCase--;
	}
	totalDistCount=co.getDistCount();
	
	//storing cv data in a file..
	ofstream outfile("CVDATA.txt");
	
	while(cvTemp)
	{
			scanf("%s",str);
					outfile << str << " ";
			scanf("%s",str);
					outfile << str << " ";
			scanf("%s",str);
					outfile << str << " ";
				while(strcmp(str,"######")!=0)
				{		
					scanf("%s",str);
					outfile << str << " ";
				}
		outfile << "\n";
		cvTemp--;
	}
	
	outfile.close();
	
	
	//setting value for k;
	
	double primary=pi.getProbability(),social=so.getProbability(),promotional=pr.getProbability();	
	double P_Pr_Mes,P_Pi_Mes,P_So_Mes,error=0.0,minError=208239.0;
	int minFit=30;
	P_Pr_Mes=P_Pi_Mes=P_So_Mes=1.0;
	FILE * ptr;

	for(int i=30;i>0;i--)
	{
		overfit=i;
		primary=pi.getProbability();
		social=so.getProbability();
		promotional=pr.getProbability();
		error=0.0f;
		cvTemp=cvSet;
		ptr=fopen("CVDATA.txt","r");

		while(cvTemp)
		{
			primary=pi.getProbability();
			social=so.getProbability();
			promotional=pr.getProbability();
	
			fscanf(ptr,"%s",str);
			fscanf(ptr,"%s",str);
			if(strcmp(str,"Primary")==0)
			{
				fscanf(ptr,"%s",str);
				while(strcmp(str,"######"))
				{	
					primary*=pi.getStringProbability(str);
					social*=so.getStringProbability(str);
					promotional*=pr.getStringProbability(str);
					fscanf(ptr,"%s",str);	
				}
				P_Pi_Mes=primary/(primary+social+promotional);
				P_Pr_Mes=promotional/(promotional+social+primary);
				P_So_Mes=social/(promotional+social+primary);
				error+=1-P_Pi_Mes+P_Pr_Mes+P_So_Mes;
			}
			else if(strcmp(str,"Social")==0)
			{
				fscanf(ptr,"%s",str);
				while(strcmp(str,"######"))
				{
					primary*=pi.getStringProbability(str);
					social*=so.getStringProbability(str);
					promotional*=pr.getStringProbability(str);
					fscanf(ptr,"%s",str);
				}
				P_Pi_Mes=primary/(primary+social+promotional);
				P_Pr_Mes=promotional/(promotional+social+primary);
				P_So_Mes=social/(promotional+social+primary);
				error+=1+P_Pi_Mes+P_Pr_Mes-P_So_Mes;
			}
			else if(strcmp(str,"Promotional")==0)
			{
				fscanf(ptr,"%s",str);
				while(strcmp(str,"######"))
				{
					primary*=pi.getStringProbability(str);
					social*=so.getStringProbability(str);
					promotional*=pr.getStringProbability(str);
					fscanf(ptr,"%s",str);
				}
				P_Pi_Mes=primary/(primary+social+promotional);
				P_Pr_Mes=promotional/(promotional+social+primary);
				P_So_Mes=social/(promotional+social+primary);
				error+=1+P_Pi_Mes-P_Pr_Mes+P_So_Mes;
			}		
			cvTemp--;
		}
		fclose(ptr);
		if(error <= minError)
			minFit=overfit;
	}
	overfit=minFit;			
	// reading the query mail..
	
	promotional=pr.getProbability(),primary=pi.getProbability(),social=so.getProbability();
	printf("\n\n\nEnter message\t:");
	
	printf("Taking the input now..(write ###### at the end of input message)\n");
	scanf("%s",str);
	
	scanf("%s",str);
	while(strcmp(str,"######"))
	{
		primary*=pi.getStringProbability(str);
		social*=so.getStringProbability(str);
		promotional*=pr.getStringProbability(str);
				
		scanf("%s",str);
	}
	
	printf("\nProbability of message in promotional : %f\n",promotional/(primary+promotional+social));
	
	printf("Probability of message in primary : %f\n",primary/(primary+promotional+social));
		
	printf("Probability of message in social : %f\n",social/(primary+promotional+social));		
	return 0;
}
