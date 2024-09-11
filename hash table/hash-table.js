// hash Map 哈希表
const map = new Map();
map.set(123, '你好')
map.set(2323, '我很好')
map.set(2204313382, 'sunfishlk')
// set(key,value)方法第一个参数是key，第二个是value

let id = map.get(2204313382)
console.log(id)

// forEach((value,key)=>{})  forEach返回的是value和key，先是value再是key
map.forEach((value, key)=>{
    console.log(key, value, '\n')
})

// 遍历
for(const [k,v] of map.entries()){
    console.log(k,'->',v,'\n')
}
for(const k of map.keys()){
    console.log(k)
}
for(const v of map.values()){
    console.log(v)
}