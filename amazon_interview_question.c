/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 

//the arrival packet
struct packet {
    int priority;
};
//the arrival packet in the interface
struct packet_interface {
    struct packet pck;
    int arrival_time;
    struct packet_interface* next;
};

int chooseRandoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    //printf("%d ", num); 
    return num;

}
//funct insert(packet_inter) add the arrival packet_inter to the memory
void insert(struct packet_interface pck_inter_local,
    struct packet_interface* head0,
    struct packet_interface *head1,
    struct packet_interface*head2,
    struct packet_interface*head3, 
    struct packet_interface*tail0,
    struct packet_interface*tail1,
    struct packet_interface*tail2,
    struct packet_interface*tail3,
    int cnt_avaibalbe_packet,
    int holes_val,
    struct packet_interface*wrt_ptr,
    struct packet_interface *ptr_to_last_hole,
    struct packet_interface * memory_packets
) {
    if (cnt_avaibalbe_packet == 99) {
        printf("\n          ERROR: PACKET INTERFACE MEMORY IS FULL   \n");
    }
    else {
        cnt_avaibalbe_packet++;
        if (holes_val != 0) {
            holes_val--;
        }
        struct packet_interface* next_of_delete_packet = wrt_ptr->next;
        *wrt_ptr = pck_inter_local;
        printf("\nInserted Packet: time:%d , priority:%d\n", pck_inter_local.arrival_time, pck_inter_local.pck.priority);
        //update the heads/tails pointers
        if (wrt_ptr->pck.priority == 0) {
            if (head0 == NULL) {
                head0 = wrt_ptr;
                tail0 = wrt_ptr;
            }
            else {

                tail0->next = wrt_ptr;
                tail0 = tail0->next;
            }
        }
        else if (wrt_ptr->pck.priority == 1) {
            if (head1 == NULL) {
                head1 = wrt_ptr;
                tail1 = wrt_ptr;
            }
            else {
                tail1->next = wrt_ptr;
                tail1 = tail1->next;
            }
        }
        else if (wrt_ptr->pck.priority == 2) {
            if (head2 == NULL) {
                head2 = wrt_ptr;
                tail2 = wrt_ptr;
            }
            else {
                tail2->next = wrt_ptr;
                tail2 = tail2->next;
            }
        }
        else {
            if (head3 == NULL) {
                head3 = wrt_ptr;
                tail3 = wrt_ptr;
            }
            else {
                tail3->next = wrt_ptr;
                tail3 = tail3->next;
            }
        }
        if (holes_val == 0) {
            wrt_ptr = &memory_packets[cnt_avaibalbe_packet];
        }
        else {    //each hole have a pointer to the next hole
            wrt_ptr = next_of_delete_packet;
        }
    }
}

//funct get_packet() return the packet interface from the memory according to the rules order
struct packet_interface get_packet(
    struct packet_interface* head0,
    struct packet_interface* head1,
    struct packet_interface* head2,
    struct packet_interface* head3,
    struct packet_interface* tail0,
    struct packet_interface* tail1,
    struct packet_interface* tail2,
    struct packet_interface* tail3,
    int cnt_avaibalbe_packet,
    int holes_val,
    struct packet_interface* wrt_ptr,
    struct packet_interface* ptr_to_last_hole,
    struct packet_interface* memory_packets
    ) {
    bool get_succes = 1;
    struct packet_interface* output_packet = NULL;
    if (head0 != NULL) {
        output_packet = head0;
        if (head0 != tail0) {
            head0 = head0->next;
        }
        else {
            head0 = NULL;
            tail0 = NULL;
        }
    }
    else if (head1 != NULL) {
        output_packet = head1;
        if (head1 != tail1) {
            head1 = head1->next;
        }
        else {
            head1 = NULL;
            tail1 = NULL;
        }
    }
    else if (head2 != NULL) {
        output_packet = head2;
        if (head2 != tail2) {
            head2 = head2->next;
        }
        else {
            head2 = NULL;
            tail2 = NULL;
        }
    }
    else if (head3 != NULL) {
        output_packet = head3;
        if (head3 != tail3) {
            head3 = head3->next;
        }
        else {
            head3 = NULL;
            tail3 = NULL;
        }
    }
    else {
        printf( "\nERROR: YOU TRY TO GET A PACKET, BUT NO PACKET IS AVAIABLE");
        get_succes = 0;
    }
    if (get_succes == 1) {
        cnt_avaibalbe_packet--;
        holes_val++;
        ptr_to_last_hole = output_packet;
        if (holes_val == 1) {
            wrt_ptr = output_packet;
            ptr_to_last_hole = wrt_ptr;
        }
        else {
            ptr_to_last_hole->next = output_packet;
        }
        printf("\n   Get   Packet: time:%d , priority:%d\n", output_packet->arrival_time, output_packet->pck.priority);

    }
    return *output_packet;
}

int main()
{
    struct packet_interface memory_packets[100]; //memory array of the packets interface
//pointers to write/read from the memory
    struct packet_interface* head0 = NULL, * head1 = NULL, * head2 = NULL, * head3 = NULL, * tail0 = NULL, * tail1 = NULL, * tail2 = NULL, * tail3 = NULL;
    int holes_val = 0, cnt_avaibalbe_packet = 0;
    struct packet_interface  * wrt_ptr = memory_packets, * ptr_to_last_hole=NULL;
    ////////////////
    /////packets declarations
    struct packet pck1, pck2, pck3, pck4;
    struct packet_interface pck1_inter;

    //funct insert(packet_inter) add the arrival packet_inter to the memory
 
    int curr_time = 0, nmbr_or_inserted_packets = 0;
    srand(time(0));
    while (nmbr_or_inserted_packets < 320) {
        pck1.priority = chooseRandoms(0, 3);
        pck1_inter.pck = pck1;
        pck1_inter.arrival_time = curr_time;
        curr_time++;
        insert(pck1_inter,
            head0,
            head1,
           head2,
            head3,
           tail0,
            tail1,
           tail2,
            tail3,
           cnt_avaibalbe_packet,
            holes_val,
            wrt_ptr,
            ptr_to_last_hole,
            memory_packets);
        nmbr_or_inserted_packets++;
        if (chooseRandoms(0, 1)) {
            get_packet(
               head0,
                head1,
                head2,
              head3,
                tail0,
                tail1,
               tail2,
              tail3,
                cnt_avaibalbe_packet,
               holes_val,
        
                wrt_ptr,
               ptr_to_last_hole,
               memory_packets);
        }
    }
  
    return 0;
}

