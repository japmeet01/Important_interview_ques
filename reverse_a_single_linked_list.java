import java.util.ArrayList;

public class reverse_a_single_linked_list {public static void main(String args[])
{
    Node head=new Node(10);
    head.next=new Node(20);
    head.next.next=new Node(30);
    printlist(head);
    head=efficient_reverse(head);
    printlist(head);

}

    static Node efficient_reverse(Node head){
        Node curr=head;
        Node prev=null;
        while(curr!=null){
            Node next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    static Node naive_reverse(Node head){
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for(Node curr = head; curr!=null; curr=curr.next){
            arr.add(curr.data);
        }
        for(Node curr = head; curr!=null; curr=curr.next){
            curr.data=arr.remove(arr.size()-1);
        }
        return head;
    }

    public static void printlist(Node head){
        Node curr=head;
        while(curr!=null){
            System.out.print(curr.data+" ");
            curr=curr.next;
        }System.out.println();
    }
}
