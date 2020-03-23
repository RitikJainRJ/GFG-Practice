int tour(petrolPump p[],int n){

    for(int i = 0; i < n; i++){
        if(p[i].petrol >=  p[i].distance){
            int v = 0;
            int remain = 0;
            for(int j = i; v < n; j = (j + 1) % n, v++){
                remain += (p[j].petrol - p[j].distance);
                if(remain < 0)
                    break;
            }
            if(v == n)
                return i;
        }
    }
    return -1;
}
