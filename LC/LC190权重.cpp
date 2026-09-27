int reverseBits(int n) {
        int num=0;
        for(int i=0;i<32;i++){
            num=num*2+n%2;//num左移1,n取最低位
            n/=2;//n右移1
        }
        return num;
    }