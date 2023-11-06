class SeatManager {
    TreeSet<Integer> seat= new TreeSet<Integer>();
    public SeatManager(int n) {
        for(int i=1;i<=n;++i)
        {
            seat.add(i);
        }
    }
    
    public int reserve() {
        return seat.pollFirst();
    }
    
    public void unreserve(int seatNumber) {
        seat.add(seatNumber);
    }
}