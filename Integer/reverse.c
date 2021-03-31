
// int reverse(int x){
    // int sign;
    // int flag=0;
    // int t=0;

    // if(x<0)
    // {
        // sign=-1;
        // x=-x;
    // }
    // else if(x>0)
    // {
        // sign=1;
    // }
    // else
    // {
        // return 0;
    // }

    // while(0!=x/10)
    // {
        // int t1=x%10;
        // t=t*10+t1;
        // x/=10;
        // flag=1;
    // }

    // if(flag)
    // {
        // if((t*10+x)*sign>(pow(2,31)-1)||(t*10+x)*sign<(-1*pow(2,31)))
            // return 0;
        // else 
            // return (t*10+x)*sign;//t*10可能会溢出，因此这种方法不能通过
    // }
    // else
    // {
        // return x*sign;
    // }
// }
int reverse(int x){
   int ret=0;
   while(x!=0)
   {
       int pop=x%10;
       if(ret>(pow(2,31)-1)/10||(ret==(pow(2,31)-1)/10&&pop>7))//利用int最大值个位为7
			return 0;
       if(ret<(-1*pow(2,31))/10||(ret==(-1*pow(2,31))/10&&pop<-8))//利用int最小值个位为8
			return 0;
       ret = ret*10+pop;
       x/=10;
   }
   return ret;
}