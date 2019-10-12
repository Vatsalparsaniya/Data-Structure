# counter function
def counter(list,key):
  count = 0
  for i in list:
    if i == key:
      count += 1
  
  return count


counter([12, 43, 436, 23, 32, 634, 23, 324, 2342, 24, 23], 23)
