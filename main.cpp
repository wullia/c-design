#include "func.cpp"

  main(){
    char opnm;
    Lnode l=CreateList();
    system("cls");
    printf("******Menu******\n");
    printf("1�� ������Ϣ\n");
    printf("2�� ��ʾ�ɼ�\n");
    printf("3�� ����\n");
    printf("4�� �ɼ���ѯ\n");
    printf("5�� �޸�\n");
    printf("6�� ɾ���ɼ�\n");
    printf("7�� �˳�ϵͳ \n");
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