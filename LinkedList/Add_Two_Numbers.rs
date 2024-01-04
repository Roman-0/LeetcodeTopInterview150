//Roman Olsen
//Leetcode top 150
// #2 Add Two Numbers
//
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
//
impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut return_list = Some(Box::new(ListNode::new(0))); 
        let mut node = &mut return_list;

        let mut l1c = l1.clone();
        let mut l2c = l2.clone();

        let mut carry: u8 = 0;

        while l1c.is_some() || l2c.is_some() || carry > 0 {
            let val1: i32 = l1c.as_ref().map_or(0, |node| node.val); // when l1c is None
            let val2: i32 = l2c.as_ref().map_or(0, |node| node.val); // when l2c is None

            let sum: u8 = (val1 + val2 + carry as i32) as u8;
            carry = sum / 10;

            // Create a new ListNode and set its value
            let new_node = Some(Box::new(ListNode::new((sum % 10).into())));

            // Connect the new node to the existing list
            node.as_mut().unwrap().next = new_node;

            // Move to the next node
            node = &mut node.as_mut().unwrap().next;

            // Move to the next nodes in l1c and l2c
            if let Some(n) = l1c.as_mut() {
                l1c = n.next.take();
            }
            if let Some(n) = l2c.as_mut() {
                l2c = n.next.take();
            }
        }

        return_list.unwrap().next // Return the next of the dummy head
    }
}
