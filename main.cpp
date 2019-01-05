#include "func.cpp"

  main(){
    char opnm;
    Lnode l=CreateList();
    system("cls");
    printf("******Menu******\n");
    printf("1、 输入信息\n");
    printf("2、 显示成绩\n");
    printf("3、 排序\n");
    printf("4、 成绩查询\n");
    printf("5、 修改\n");
    printf("6、 删除成绩\n");
    printf("7、 退出系统 \n");
    scanf("%c",&opnm);
    switch (opnm){
      case '1':
       AppendNode(l);
       break;
      case '2':
       print(l);
       break;
      case '3':
      case '4':
       FindNode(l);
       break;
      case '5':
      case '6':
       DeleteNode(l);
       break;
    }
   
}