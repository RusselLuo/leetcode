package main

import(
	"fmt"
)

type dlist struct{
	prev	*dlist
	next	*dlist
	key		int
	val		int
}
type LRUCache struct {
	head	*dlist
	tail	*dlist
	keys	map[int]*dlist
	size	int
}


func Constructor(capacity int) LRUCache {
	cache:=LRUCache{nil,nil,make(map[int]*dlist),capacity}
    return cache
}


func (this *LRUCache) Get(key int) int {
    if this.keys[key]==nil{
		return -1
	}else{
		temp := this.keys[key]
		fmt.Printf("temp key: %d\n",temp.key)
		fmt.Printf("temp loc: %p, temp.prev loc: %p, temp.next loc: %p\n",temp,temp.prev,temp.next)
		if temp.prev!=nil{
			if this.tail==temp{
				this.tail = this.tail.prev
			}
			temp.prev.next = temp.next
		}
		if temp.next!=nil{
			temp.next.prev = temp.prev
			if this.head==temp{
				this.head = temp.next
			}
		}
		temp.next = this.head
		this.head.prev = temp
		this.head = temp
		return temp.val
	}
}


func (this *LRUCache) Put(key int, value int)  {
	_,ok:=this.keys[key]
	fmt.Printf("put:%d\n",key)
	if ok{
		_ = this.Get(key)
		this.keys[key].val = value
		return
	}else if this.size==len(this.keys){
		fmt.Println(this.keys)
		fmt.Printf("deleting: %d\n",this.tail.key)
		delete(this.keys,this.tail.key)
		fmt.Printf("number of keys: %d\n",len(this.keys))
		this.tail = this.tail.prev
		if this.tail!=nil{
			this.tail.next = nil
		}
	}
	temp:=&dlist{nil,this.head,key,value}
	if this.head!=nil{
		fmt.Println("already have head!")
		this.head.prev = temp
	}
	if this.tail ==nil{
		this.tail = temp
	}
	this.head = temp
	this.keys[key] = this.head
}
func main() {
	c:=Constructor(2)
	c.Put(2,1)
	c.Put(3,2)
	println(c.Get(3))
	println(c.Get(2))
	c.Put(4,3)
	println(c.Get(2))
	println(c.Get(3))
	println(c.Get(4))
}