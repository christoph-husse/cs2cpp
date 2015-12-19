using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs2Cpp
{
    interface ISCIMemberQueryable<T> : IEnumerable<T> where T : SCIMemberDefinition
    {
        int Count { get; }
        bool Contains(String memberName);
        bool Contains(T member);
    }

    [Serializable]
    class SCIMemberQueryable<T> : ISCIMemberQueryable<T> where T : SCIMemberDefinition
    {
        public static readonly ISCIMemberQueryable<T> Empty = new SCIMemberQueryable<T>();

        private readonly HashSet<T> _sortedMembers = new HashSet<T>();
        private readonly HashSet<String> _usedNames = new HashSet<string>();

        public SCIMemberQueryable()
        {
        }

        public SCIMemberQueryable(IEnumerable<T> members)
        {
            members.Apply(e => _sortedMembers.Add(e));
            members.Apply(e => { if (!_usedNames.Contains(e.Name)) _usedNames.Add(e.Name); });
        }

        public void Add(T member)
        {
            _sortedMembers.Add(member);

            if (!_usedNames.Contains(member.Name))
                _usedNames.Add(member.Name);
        }

        public bool Contains(String memberName)
        {
            return _usedNames.Contains(memberName);
        }

        public bool Contains(T member)
        {
            return _sortedMembers.Contains(member);
        }

        public int Count
        {
            get { return _sortedMembers.Count; }
        }

        public IEnumerator<T> GetEnumerator()
        {
            return _sortedMembers.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return _sortedMembers.GetEnumerator();
        }
    }

    interface ISCITypeQueryable<T> : IEnumerable<T> where T : SCITypeHandle
    {
        int Count { get; }
        bool Contains(T type);
    }


    [Serializable]
    class SCITypeQueryable<T> : ISCITypeQueryable<T> where T : SCITypeHandle
    {
        private readonly List<T> _types = new List<T>(); 
        private readonly HashSet<T> _sortedTypes = new HashSet<T>();

        public SCITypeQueryable()
        {
        }

        public SCITypeQueryable(IEnumerable<T> types)
        {
            _types = types.ToList();
            _types.Apply(e => _sortedTypes.Add(e));
        }

        public void Add(T type)
        {
            _sortedTypes.Add(type);
        }

        public bool Contains(T type)
        {
            return _sortedTypes.Contains(type);
        }

        public int Count
        {
            get { return _types.Count; }
        }

        public IEnumerator<T> GetEnumerator()
        {
            return _types.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return _types.GetEnumerator();
        }
    }
}
