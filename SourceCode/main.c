#include "header.h"
int main()
{
    int n,i,j;
    struct array *u,*b;
    printf("����δ֪������\n");
    scanf("%d",&n);
    u=create_array(n);
    b=create_array(n);
    for(i=1;i<=n;i++)
    {
        printf("���뷽��%d��ϵ�� �ո����\n",i);
        for(j=1;j<=n;j++)
        {
            scanf("%lf",modify_m(u,i,j));
        }
        scanf("%lf",modify_m(b,1,i));
        scanf("%*[^\n]%*c");
    }
    //print_array(caculate_function(u,b));
    printf("����������\n");
    print_function(u,b);
    if(value_array(u)==0){printf("�˷�����Ψһ��\n");printf("Press Any Key To Exit...");getchar();exit(0);}
    //printf("u:\n");
    //printf("%lf\n",value_array(u));
    //printf("instead_array(u,b,1):\n");
    //print_array(instead_array(u,b,1));
    //printf("%lf\n",value_array(instead_array(u,b,1)));
    //printf("x1:\n");
    //printf("%lf\n",*modify_m(caculate_function(u,b),1,1));
    //printf("instead_array(u,b,2):\n");
    //print_array(instead_array(u,b,2));
    //printf("%lf\n",value_array(instead_array(u,b,2)));
    //printf("x2:\n");
    //printf("%lf\n",*modify_m( caculate_function(u,b),1,2));
    for(i=1;i<=n;i++)
    {
        printf("X%d:",i);
        //printf("%lf\n",*modify_m( caculate_function(u,b),1,i));
        if(print_fraction(value_array(instead_array(u,b,i)),value_array(u))==-1)
        {
            printf("%g\n",*modify_m( caculate_function(u,b),1,i));
        }
        /*else
        {
            print_fraction(value_array(instead_array(u,b,i)),value_array(u));
        }*/
    }
    getchar();
    printf("Press Any Key To Exit...");



    getchar();

    return 0;
}
