Stack<Integer> stack = new Stack<>();
stack.push(1);
stack.push(2);
stack.push(3);

Object[] array = stack.toArray();
for (int i = 0; i < array.length; i++) {
    System.out.println(array[i]);
}