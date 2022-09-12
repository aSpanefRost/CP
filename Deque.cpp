void insert(deque<int>& dq, int num) {
  while(dq.size() and dq.back() < num) {
    dq.pop_back();
  }
  dq.push_back(num);
}

void remove(deque<int>& dq, int num) {
  if(dq.front() == num) dq.pop_front();

}


 void solve()
 {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    deque<int> dq;

    for(int i = 0; i < n; i++) {
      if(i < k) {
        insert(dq, arr[i]);
        if(i == k-1) {
          cout << dq.front();
        }
      }
      else {
        remove(dq, arr[i-k]);
        insert(dq, arr[i]);
        cout << dq.front();
      }
    }

 }
