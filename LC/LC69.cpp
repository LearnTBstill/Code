int mySqrt(int x) {
        int left=0,mid=0,right=x,ans=0;
        while(left<=right)//等不等于取决于区间是否是闭区间
        {
            mid=left+(right-left)/2;//写成这个也是为了防止溢出(原理不是取模是恒等变形)
            if((long long)mid*mid>x) {right=mid-1;}//强转为longlong，不然int会溢出
            else{ans=mid;left=mid+1;}   //ans用来记录mid，mid是有可能成为结果的
        }
        return ans;
    }