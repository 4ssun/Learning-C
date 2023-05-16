#include <stdio.h>
#include <stdlib.h>

int main()
{
  double exe_fix, provao, prova_diss, prova_ele;
  double media;

  printf("Informe sua nota de exercicio de fixacao!:");
  scanf("%f", &exe_fix);
  printf("Informe agora a sua nota da prova dissertativa");
  scanf("%f", &prova_diss);
  printf("Informe tambem sua prova eletronica:");
  scanf("%f", &prova_ele);

  media = exe_fix * 0.20 + prova_diss * 0.30 + prova_ele * 0.50;
  if (media >= 6.00)
  {
    printf("Parabens, voce foi aprovado com a media de  %.2f\n", media);
    system("pause");
  }
  else
  {
    printf("Boa sorte na prova de recuperacao, sua media foi de %.2f\n, espero que se saia bem..", media);
    system("pause");
  }
}
