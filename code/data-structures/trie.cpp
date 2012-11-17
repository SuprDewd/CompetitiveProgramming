template <class T>
class trie {
private:
	struct node {
		map<T, node*> children;
		int prefixes;
		int words;

		node() {
			prefixes = words = 0;
		}
	};

	node* root;

public:
	trie() {
		root = new node();
	}

	template <class I>
	void insert(I begin, I end) {
		node* cur = root;
		while (true) {
			cur->prefixes++;
			if (begin == end) {
				cur->words++;
				break;
			} else {
				T head = *begin;
				typename map<T, node*>::const_iterator it = cur->children.find(head);
				if (it == cur->children.end()) it = cur->children.insert(pair<T, node*>(head, new node())).first;
				begin++;
				cur = it->second;
			}
		}
	}

	template<class I>
	int countMatches(I begin, I end) {
		node* cur = root;
		while (true) {
			if (begin == end) {
				return cur->words;
			} else {
				T head = *begin;
				typename map<T, node*>::const_iterator it = cur->children.find(head);
				if (it == cur->children.end()) return 0;
				begin++;
				cur = it->second;
			}
		}
	}

	template<class I>
	int countPrefixes(I begin, I end) {
		node* cur = root;
		while (true) {
			if (begin == end) {
				return cur->prefixes;
			} else {
				T head = *begin;
				typename map<T, node*>::const_iterator it = cur->children.find(head);
				if (it == cur->children.end()) return 0;
				begin++;
				cur = it->second;
			}
		}
	}
};