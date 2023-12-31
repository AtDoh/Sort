정렬(Sorting)
===
**주어진 데이터를 정해진 순서대로 나열하는 것.**
***
데이터가 커지는 순서대로 정렬될 경우 **오름차순(Ascending Order) 정렬**이라고, 데이터가 작아지는 순서대로 정렬되는 경우 **내림차순(Descending Order) 정렬**이라 한다.


만약 데이터의 중복이 허용되는 경우 데이터가 커지거나 같아지는 순서대로 정렬하는 경우 **비내림차순(Non-Descending Order) 정렬**이라고하고,
데이터가 작아지거나 같아지는 순서대로 정렬하는 경우를 **비오름차순(Non-Ascending Order)** 정렬이라고도 한다.

***
정렬 알고리즘은 몇 가지 분류로 나눌 수 있다.
## 비교 여부(Comparison)
### 비교 정렬
비교연산자를 사용하여 두 값을 비교하여 정렬을 수행하는 알고리즘.

비교 정렬이 작동하려면 
1. a<=b 이고 b<=c 이면 a<=c 라는 타동성.
2. a 와 b 모두 a<=b 또는 b<=a 라는 완전성(or 3분법)
이 두가지 원리가 필요하다.

비교 정렬은 O(n log n) 보다 좋은 성능을 낼 수 없다.

### 비 비교 정렬


***
## 안전성 여부(Stablity)
### 안정(Stable) 정렬
중복되는 값들은 정렬된 이후에도 입력된 순서와 동일한 순서대로 정렬되는 정렬 알고리즘.

만약 데이터가 도시,시간 으로 주어져 있고 최초에 시간순서대로 정렬되어 있다고 생각하자. 이 정렬된 데이터를 도시를 사전순으로 정렬하고 도시별로 다시 시간순으로 정렬한다고 생각해보자.

안정 정렬을 사용할 경우 주어진 데이터를 다시 도시순으로 정렬 해주면 끝이지만, 불안정 정렬을 사용할 경우 도시별로 정렬한 이후에 다시 각 도시별로 시간을 정렬하는 과정이 필요하다.

만약 빠른 속도로 정렬을 하는 불안정 정렬 알고리즘이 있더라도 이러한 경우에는 더 오랜 시간이 걸릴 수 있다는 것이다.

### 불안정(Unstable) 정렬
중복되는 값들이 정렬된 이후에도 입력된 순서와 동일하다는 보장이 없는 정렬 알고리즘.
***
## 메모리 사용량(또는 추가적인 컴퓨팅 자원 사용량)
### 제자리 정렬(in-place)
정렬하고자 하는 데이터를 저장하는 메모리 공간 이외에 O(1) 이내의 메모리 공간을 추가적으로 필요하는 정렬 알고리즘. O(1) 는 정렬할 원소들에 비해서 충분히 무시할 만한 크기이다.

제자리 알고리즘은 메모리 사용량이 적은 것 뿐만 아니라 공간 지역성(Spatial Locality) 측면에서도 이득이다. 

### not-in-place or out-of-place
정렬할 원소들외에 추가적인 메모리 공간을 필요로 하는 정렬 알고리즘. 알고리즘 별로 필요로 하는 공간 복잡도가 다르다. 
***
## 방식(Method)
### 교환(exchange)
### 선택(selection)
n 번째 항목을 찾는 알고리즘.

n 번째 항목에는 최대,최소,중앙 항목 또한 포함된다.
### 삽입(insertion)
### 병합(merging)
### 파티셔닝(partitioning)
***
## 적응형(Adaptability)
입력의 사전 정렬이 실행시간에 영향을 미치는지 여부.
### 적응형(Adaptive)
정렬을 수행할 때, 입력의 기존 순서를 활용하는 정렬 알고리즘.
### 비적응형
***
## 병행성(Parallel)
### 직렬(Serial)

### 병렬(Parallel)
***
## 실시간성
### 비실시간 정렬(offline)
정렬할 모든 데이터를 입력 받아두고 정렬을 수행하는 알고리즘
### 실시간 정렬(online)
실시간 스트림을 입력으로 받으면서 정렬을 수행하는 알고리즘
***
## 재귀여부(Recursion)
***
## 데이터 위치
### 내부 정렬(Internal)
모든 데이터를 주메모리 상에 적재해 두고 정렬을 수행하는 알고리즘. 이러한 알고리즘은 대상 데이터가 주메모리 보관될 만큼 충분히 작은 경우에 사용할 수 있다.
### 외부 정렬(External)
대량의 데이터처럼 주메모리에 모든 데이터를 적재 시킬 수 없는 경우, 파일 등 을 사용하여 보조기억장치에 데이터를 분산하고 이들 중 일부만 주메모리에 적재시켜 정렬을 수행하는 정렬 알고리즘.
***