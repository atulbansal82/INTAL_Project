#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 1001

char* set_INTAL()
{
   char* INTAL=(char*)malloc(n*sizeof(char));
   int index=0;
   for(index=0;index<n-1;index++)
   {
       INTAL[index]='0';
   }
   INTAL[index]='\0';

   return INTAL;
}

int length(char* intal)
{
    // return length of INTALs
    return strlen(intal);
}

// A function that accepts two INTALs as function parameters and returns 0 or -1 or 1 if both INTALs are equal or first INTAL is lesser than second INTAL or second INTAL is lesser than first INTAL respectively.
int compareINTAL(char* first_intal, char* second_intal)
{
    // if length of first_intal > length of second_intal
    if(length(first_intal) > length(second_intal))
    return 1;

    // if length of first_intal < length of second_intal
    else if(length(first_intal) < length(second_intal))
    return -1;
    
    // if length of first_intal = length of second_intal
    else
    {
        int i=0;
        while(i<length(first_intal))
        {
           if(first_intal[i] > second_intal[i])
           return 1;

           if(first_intal[i] < second_intal[i])
           return -1;

           i+=1;
        }
        // if both are equal
        return 0;
    }
}

//Swap two intal
void str_swap(char** str1,char** str2) {
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
//A function that accepts two INTALs as function parameters and returns the sum of both INTALs AND Use the same concept of elementary mathematical addition for adding the INTALs
char* adding_INTAL(char* str1,char* str2)
{
    if (length(str1) > length(str2))
        str_swap(&str1, &str2);

    char *result = set_INTAL();
    int n1 = length(str1);
    int n2 = length(str2);
    strrev(str1);
    strrev(str2);
    int carry = 0;
    int i = 0;
    for (i = 0; i < n1; i++)
    {
        int sum = (str1[i] - '0') + (str2[i] - '0') + carry;
        result[i] = (sum % 10 + '0');
        carry = sum / 10;
    }
    int j = 0;
    for (j = n1; j < n2; j++)
    {
        int sum = (str2[j] - '0') + carry;
        result[j] = (sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
    {
        result[n2] = carry + '0';
        result[n2 + 1] = '\0';
    }
    else
        result[n2] = '\0';

    strrev(result);
    return result;
}

//A function that accepts two INTALs as function parameters and returns the difference of both INTALs
char* subtract_INTAL(char* intal1,char* intal2)
{
    if(compareINTAL(intal1,intal2)==0)
    {
        char* ans=set_INTAL();
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }

    if(compareINTAL(intal1,intal2)==-1)
    str_swap(&intal1,&intal2);

    int L1=length(intal1);
    int L2=length(intal2);
    strrev(intal1);
    strrev(intal2);

    char* ans=set_INTAL();
    int i=0,borrow=0;
    for(i=0 ; i<L2 ; i++)
    {
        int diff= (intal1[i] - '0') - (intal2[i] - '0') - borrow;
         if (diff < 0) 
         {
            diff = diff + 10;
            borrow = 1;
         }
        else
            borrow = 0;
 
        ans[i] = (diff + '0');
    }
    int j=0;
    for(j=L2 ; j<L1 ; j++)
    {
        int diff= (intal1[i] - '0') - borrow;
         if (diff < 0) 
         {
            diff = diff + 10;
            borrow = 1;
         }
        else
            borrow = 0;
 
        ans[i] = (diff + '0');
    }

    ans[L1]='\0';
    strrev(ans);

    //The result INTAL must not contain any preceding zeros in the result, unless the result is zero in which case the INTAL can contain only 1 zero.
    char* result=set_INTAL();
    i=0;
    for(i=0 ; ans[i]!='\0'; i++)
    {
        if(ans[i]!='0')
        break;
    }
    j=0;
    int k=0;
    for(j=i ; ans[j]!='\0' ; j++)
    {
        result[k]=ans[j];
        k++;
    }
    result[k]='\0';
    return result;
}

//INTALs support a maximum of 1000 digits, the sum of digits of both multipliers must not exceed 1000.
char* Multiply_INTAL(char* intal1 , char* intal2)
{
    if (length(intal1) == 0 || length(intal2) == 0)
    {
        printf(" WARNING !! ");
    }
    if (intal1[0] == '1' && length(intal1) == 1)
    {
        return intal2;
    }
    if (intal2[0] == '1' && length(intal2) == 1)
    {
        return intal1;
    }
    if (intal1[0] == '0' && length(intal1) == 1)
    {
        char *result = set_INTAL();
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    if (intal2[0] == '0' && length(intal2) == 1)
    {
        char *result = set_INTAL();
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    char* result=set_INTAL();
    int L1=length(intal1);
    int L2=length(intal2);
    int i=0,j=0;
    int ptr1=1;
    for(i=L2-1 ; i>=0 ; i--)
    {
        int sum=0,carry=0;
        int ptr2=L2+L1-ptr1;

        for(j=L1-1 ; j>=0 ; j--)
        {
            sum = (intal1[j]-'0')*(intal2[i]-'0') + (result[ptr2]-'0') + carry;
            result[ptr2] = sum%10 + '0';
            carry = sum/10;
            --ptr2;
        }
        if(carry)
        result[ptr2] = carry+'0';
        ++ptr1;
    }
    result[L1+L2]='\0';

    //The result INTAL must not contain any preceding zeros in the result, unless the result is zero in which case the INTAL can contain only 1 zero.
    char* ans=set_INTAL();
    i=0;
    for(i=0 ; result[i]!='\0'; i++)
    {
        if(result[i]!='0')
        break;
    }
    j=0;
    int k=0;
    for(j=i ; result[j]!='\0' ; j++)
    {
        ans[k]=result[j];
        k++;
    }
    ans[k]='\0';
    return ans;
}

// Function for Division
char * division_INTAL(char* dividend,long int divisor,long int* remainder)
{
    if(dividend[0]=='0' && length(dividend)==1)
    {
        char* ans=set_INTAL();
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }
   
    char* quotient=set_INTAL();
    long temp=0;
    int i=0,j=0;

    while(dividend[i]){
        
         temp = temp*10 + (dividend[i] -48);
         if(temp<divisor){
            
             quotient[j++] = 48;
            
         }
         else{
             quotient[j++] = (temp / divisor) + 48;;
             temp = temp % divisor;

         }
         i++;
    }

    quotient[j] = '\0';
    *remainder = temp;

    //The result INTAL must not contain any preceding zeros in the result.
    char* ans=set_INTAL();
    i=0;
    for(i=0 ; quotient[i]!='\0'; i++)
    {
        if(quotient[i]!='0')
        break;
    }
    j=0;
    int k=0;
    for(j=i ; quotient[j]!='\0' ; j++)
    {
        ans[k]=quotient[j];
        k++;
    }
    ans[k]='\0';
    return ans;
    
}

//A function to take an unsigned int n as parameter and return the nth Fibonacci INTAL.
char* FibonacciINTAL(unsigned int x)
{
   char* a= set_INTAL();
   a[0]='0';
   a[1]='\0';

   if(x==0)
   return a;

   char* b= set_INTAL();
   b[0]='1';
   b[1]='\0';

   if(x==1)
   {
       free(a);
       return b;
   }
   int i=0;
   for(i=2 ; i<=x ; i++)
   {
       char* temp=adding_INTAL(a,b);
       free(a);
       a=b;
       a=strrev(a);
       b=temp;
   }
   return b;
}

// A function to take an unsigned int n as parameter and return the factorial represented as an INTAL.
char* Factorial_INTAL(unsigned int x)
{
    char* result = (char*)malloc(2*sizeof(char));
    result[0]='1';
    result[1]='\0';

    if(x==1 || x==0)
    return result;

    char* temp = (char*)malloc(2*sizeof(char));
    temp[0]='1';
    temp[1]='\0';
    char* num;
    int i=0;
    for(i=2 ; i<=x ; i++)
    {
       num = adding_INTAL(temp,"1");
       temp = num;
       num = Multiply_INTAL(temp,result);
       result = num;    
    }
    return result;
}

int main()
{
    //Creating Two INTALs for comaparision
    char* INTAL1 = (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL1,"7596");
    char* INTAL2= (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL2,"5849");

    //comparision of Two INTAls
    if(compareINTAL(INTAL1 , INTAL2)==1)
       printf("1st INTAL is larger than 2nd INTAL ");
    else if(compareINTAL(INTAL1 , INTAL2)==-1)
      printf("2nd INTAL is larger than 1st INTAL ");
    else if(compareINTAL(INTAL1 , INTAL2)==0)
      printf("Both INTALs are Equal");
    printf("\n");

    free(INTAL1);
    free(INTAL2);


    //Creating Two INTALs for Addition
    INTAL1 = (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL1,"7596");
    INTAL2= (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL2,"5849");

    //Addition of Two INTAls
    char* ans_addition = adding_INTAL(INTAL1 , INTAL2);
    printf("Addition of Two INTALs : ");
    int i=0;
    for(i=0 ; ans_addition[i]!='\0' ; i++)
    printf("%c",ans_addition[i]);
    printf("\n");

    free(INTAL1);
    free(INTAL2);


    //Creating Two INTALs for substraction
     INTAL1 = (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL1,"7596");
     INTAL2= (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL2,"5849");

    //Subtraction of Two INTALs 
    char* ans_substraction = subtract_INTAL(INTAL1 , INTAL2);
    printf("Subtraction of Two INTALs : ");
     i=0;
    for(i=0 ; ans_substraction[i]!='\0' ; i++)
    printf("%c",ans_substraction[i]);
    printf("\n");

    free(INTAL1);
    free(INTAL2);


    //Creating Two INTALs for Multiplication
     INTAL1 = (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL1,"7596");
     INTAL2= (char*) malloc(1001 * sizeof(char));
    strcpy(INTAL2,"5849");

    //Multiplication of Two INTALs
    char* ans_Multiplication = Multiply_INTAL(INTAL1 , INTAL2);
    printf("Multiplication of Two INTALs : ");
     i=0;
    for(i=0 ; ans_Multiplication[i]!='\0' ; i++)
    printf("%c",ans_Multiplication[i]);
    printf("\n");

    free(INTAL1);
    free(INTAL2);


    //Test sample for Division
     char* dividend = (char*) malloc(1001 * sizeof(char));
     strcpy(dividend,"7596");
     long int divisor=25,remainder=0;
     char* quotient = division_INTAL(dividend,divisor,&remainder);
     printf("Quotient : ");
     i=0;
    for(i=0 ; quotient[i]!='\0' ; i++)
     printf("%c",quotient[i]);
    printf("\tRemainder : ");
    printf("%lu",remainder);
    printf("\n");


    int Number=20;
    //fibonacci series
    char* ans_Fibonacci = FibonacciINTAL(Number);
    printf("%dth Fibonacci number is : ",Number);
     i=0;
    for(i=0 ; ans_Fibonacci[i]!='\0' ; i++)
    printf("%c",ans_Fibonacci[i]);
    printf("\n");

    //Factorial of a given number
    char* ans_Factorial = Factorial_INTAL(Number);
    printf("Factorial of %d is : ",Number);
     i=0;
    for(i=0 ; ans_Factorial[i]!='\0' ; i++)
    printf("%c",ans_Factorial[i]);
    printf("\n");

    return 0;
}