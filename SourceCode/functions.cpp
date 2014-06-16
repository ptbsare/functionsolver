//分数输出一系列函数
int mea_int(int o)
{
    int j=1;
    int i=0;
    while(o>=j)
    {
        j*=10;
        i++;
    }
    return i;
}
int max_pub(int a,int b)
{
    int time=0;
    int r,q;
    int temp;
    r=a>=b?a:b;q=a>=b?b:a;
    while(r%q!=0)
    {
        temp=r%q;
        r=temp>=q?temp:q;
        q=temp>=q?q:temp;
        time++;
        if(time>=800){return 0;}
    }
    return q;
}
int print_fraction(double a,double b)
{
    double q=fabs(a);
    double w=fabs(b);
    int i,j;
    int temp;
    int flag=1;
    if(a*b==0){printf("0\n");return 0;}
    if(a*b>=0){flag=1;}
    else flag=0;
    int lef_q,lef_w;
    double rig_q,rig_w;
    lef_q=q;rig_q=q-lef_q;
    lef_w=w;rig_w=w-lef_w;
    while(!(rig_q<=0.00000000001&&rig_w<=0.00000000001))
    {
        lef_q*=10;
        lef_w*=10;
        rig_q*=10;
        rig_w*=10;
        q=lef_q+rig_q;
        w=lef_w+rig_w;
        lef_q=q;rig_q=q-lef_q;
        lef_w=w;rig_w=w-lef_w;
    }
    if(max_pub((int)q,(int)w)==0){return -1;}
    while(max_pub((int)q,(int)w)!=1)
    {
        temp=max_pub((int)q,(int)w);
        q=q/temp;
        w=w/temp;
    }
    if(w==1){if(flag==0)printf("-");printf("%d\n",(int)q);return 0;}
    else
    {
        printf("\n");
        if(flag==0){printf("  ");}
        printf("%d\n",(int)q);
        if(flag==0){printf("- ");}
        for(i=1;i<=(mea_int((int)q)>=mea_int((int)w)?mea_int((int)q):mea_int((int)w));i++)
    {
        printf("-");
    }
        printf("\n");
        if(flag==0){printf("  ");}
        printf("%d\n",(int)w);
    }

}

//行列式操作一系列函数
double *modify_m(struct array *p,int x,int y)
{
    int i;
    struct array *p1;
    for(p1=p;!(p1->x==x&&p1->y==y);p1=p1->next)
    {

    }

    return &p1->m;

}
void print_array(struct array *p1)
{
    int i,j;
    int n=p1->m;
    p1=p1->next;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)
        {
            printf("%.0lf ",p1->m);
            p1=p1->next;
        }
        printf("\n");

    }

}
//方程操作一系列函数
void print_function(struct array *p1,struct array *p2)
{
    int i,j;
    int n=p1->m;
    p1=p1->next;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)
        {
            if(p1->m>0)
                printf("%g*X%d",p1->m,j);
            else
                printf("(%g)*X%d",p1->m,j);
            if(j!=n)printf("+");else printf("=");
            p1=p1->next;
        }
        printf("%g",*modify_m(p2,1,i));
        printf("\n");

    }



}
//行列式操作一系列函数
struct array *create_array(int n)
 {
     int i,j;
     struct array *p1,*p2;
     p2=(struct array *)malloc(sizeof(struct array));
     p2->next=p1=(struct array *)malloc(sizeof(struct array));;
     for (i=1;i<=n*n;i++)//create
     {
         p1->next=(struct array *)malloc(sizeof(struct array));
         p1=p1->next;

     }
     p1->next=NULL;
     p1=p2;//Init
     p1->x=p1->y=0;
     p1=p1->next;
     for(i=1;i<=n;i++)
     {

         for(j=1;j<=n;j++)
         {
             p1->x=i;
             p1->y=j;
             p1=p1->next;
         }

     }
     *modify_m(p2,0,0)=(double)n;
     return p2;

 }
struct array *copy_array(struct array *p1)
{
    int i,j;
    int n=(int)p1->m;
    struct array *p2=create_array(n);
    p2->m=n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            *modify_m(p2,i,j)=*modify_m(p1,i,j);
        }
    }
    return p2;
}
struct array *son_array(struct array *p1,int x,int y)
{
    int i,j;
    int n=(int)p1->m;
    struct array *p2=create_array(((int)p1->m)-1);
    for(i=1;i<x;i++)
    {
        for(j=1;j<y;j++)
        {
            *modify_m(p2,i,j)=*modify_m(p1,i,j);
        }
        for(j=y;j<=n-1;j++)
        {
            *modify_m(p2,i,j)=*modify_m(p1,i,j+1);
        }
    }
    for(i=x;i<=n-1;i++)
    {
        for(j=1;j<y;j++)
        {
            *modify_m(p2,i,j)=*modify_m(p1,i+1,j);
        }
        for(j=y;j<=n-1;j++)
        {
            *modify_m(p2,i,j)=*modify_m(p1,i+1,j+1);
        }
    }
    return p2;
}
double value_array(struct array *p1)
{
    int i,j;
    int n=(int)p1->m;
    double sum=0;
    if((int)p1->m==1)return(*modify_m(p1,1,1));
    else
    {
        i=1;
    for(j=1;j<=n;j++)
    {
        sum=sum+pow((-1),j+1)*(*modify_m(p1,i,j))*value_array(son_array(p1,i,j));
    }
    return sum;
    }

}
struct array * instead_array(struct array *p1,struct array *p2,int y)
{
    int i,j;
    int n=(int)p1->m;
    struct array *p3=copy_array(p1);
    for(i=1;i<=n;i++)
    {
        *modify_m(p3,i,y)=*modify_m(p2,1,i);
    }
return p3;

}
//方程操作一系列函数
struct array * caculate_function(struct array *p1,struct array *p2)
{
    int i,j;
    int n=(int)p1->m;
    struct array *p3=create_array(n);
    for(i=1;i<=n;i++)
    {
    *modify_m(p3,1,i)=value_array(instead_array(p1,p2,i))/value_array(p1);
    }
return p3;
}
