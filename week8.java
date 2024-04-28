import java.util.*;

class node{
    int i;
    char ch;
    node left,right;
    node(Integer i,Character ch,node left,node right){
        this.i=i;
        this.ch=ch;
        this.left=left;
        this.right=right;
    }
}
class Mycomp implements Comparator<node>{
    public int compare(node a,node b){
        return a.i-b.i;
    }
}
public class week8{
    public static void print(node root,String s){
        if(root!=null){
        if(root.ch!='-' && root.left==null && root.right==null){
            System.out.println(root.ch+"->"+s);
            s="";
        }
        else{
            print(root.left,s+"0");
            print(root.right,s+"1");
        }
        }
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the number of district characters");
        int n = s.nextInt();
        Character[] ch = new Character[n];
        Integer[] fre = new Integer[n];
        System.out.println("enter the characters and their frequencies");
        for(int i=0;i<n;i++){
            ch[i]=s.next().charAt(0);
            fre[i]=s.nextInt();
        }
        PriorityQueue<node> pq = new PriorityQueue<node>(new Mycomp());
        node root=null;
        for(int i=0;i<n;i++){
            pq.add(new node(fre[i], ch[i],null,null));
        }
        while(pq.size()>1){
            node t1=pq.peek();
            pq.poll();
            node t2=pq.peek();
            pq.poll();
            node r=new node(t1.i+t2.i,'-',t1,t2);
            pq.add(r);
            root=r;
            System.out.println("hi");
        }
        System.out.println("ji");
        print(root,"");
    }
}