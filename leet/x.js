const json = [
  {
    _id: 'sdfhsdf',
    category: 'stack',
    groupStatus: true,

    skillGroupName: 'QA Selenium',
    skillGroupIcon: 'httpssjdfsjfsjfjfsjfds',
    skillGroupDescription: 'html string',

    skillArr: [],
  },
];

modelll.find({ category: 'stack' });
modelll.find({ category: 'skill' });

// APIs

// 1. GET -- query ? "skill"/"stack"
// 2. CREATE (Create GROUP) -- if skill category - skill,
//    skill group name
// else stack category - stack
// skill group name (stack name) along with its icon (skillGroupIcon)
// 3. Create (SKILL) --
// category -- skill
// skillName
//skillIcon
//skillDescription
//groupId

// Delete-- 1. Delete Whole Group. (group _id)
//          2. Delete only one skill (groupId, skillId)

// PUT--
// 1. GroupStatus on/off (true/false)
// 2. SkillStatus on/off (true/false)
// 3. Update Group Name (skill category only) groupId
// 4. Update Group Description (Stack Only) groupId
// 5. Update skill Description (skill only) skillId groupId
