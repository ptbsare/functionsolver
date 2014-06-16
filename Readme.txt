Usage:

Example1:

   输入未知数个数

->  2 (Input then press Enter)

   输入方程1的系数 空格隔开

->  1 -1 3 (Input then press Enter)
   
   输入方程2的系数 空格隔开

->  1 2 7 (Input then press Enter)

   方程组如下

   1*X1+(-1)*X2=3

   1*X1+2*X2=7   
X1:
   13

      --
   
      3
   
X2:
   4

      -

      3

   Press Any Key To Exit...
   
   So the answer is X1=13/3;

                    X2=4/3=1.33333333...
  
Example2:

   输入未知数个数

->  3

   输入方程1的系数 空格隔开

->  1 1 1 1

   输入方程2的系数 空格隔开

->  2 2 2 2

   输入方程3的系数 空格隔开

->  2 3 5 8

   方程组如下

   1*X1+1*X2+1*X3=1

   2*X1+2*X2+2*X3=2

   2*X1+3*X2+5*X3=8

   此方程无唯一解

   Press Any Key To Exit...
   
Example3

   输入未知数个数

->  4
   输入方程1的系数 空格隔开

->  1.345 2.3 3.5 3.5.3.4

   输入方程2的系数 空格隔开

->  1 1 1 1 1

   输入方程3的系数 空格隔开

->  2 2 22 3333 4

   输入方程4的系数 空格隔开

->  12 324 4 5 6

   方程组如下

   1.345*X1+2.3*X2+3.5*X3+3.4*X4=2

   1*X1+1*X2+1*X3+1*X4=1

   2*X1+2*X2+22*X3+3333*X4=4

   12*X1+324*X2+4*X3+5*X4=6

   X1:0.70241

   X2:-0.0113063

   X3:0.310158

   X4:-0.00126183

   Press Any Key To Exit...



Updates:

Date:1:42 5/13/2013

Edition:1.0.1

Features:

1.结果小数改为用分数表示（视情况智能选择表示形式）。

2.可以判断无唯一解的情况。

KnownIssues:

1.方程参数过大(>=1*E8)会出现假死。

2.不能直接输入分数
如 2.4*X1+(1/3)*X2=1可化为-->7.2*X1+X2=3 再输入。


Functionsolver by Ptbsare.All Rights Reserved


FirstEdition:1.0.0(1.0bate)

LatestEdition:1.0.1

Compile:G++
Report Bugs:

CreateDate:1:42 5/12/2013

