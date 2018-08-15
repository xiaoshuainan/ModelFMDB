//
//  XSNSqliteOperation.h
//  Common
//
//  Created by xsn on 2018/8/13.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SelectType) {
    KAndType = 0,
    KOrType = 1,
    KUnKnow = 2//未知
};

#define KDataBaseName @"XSNSqliteDataBase"//数据库的名称 可以根据自己自行修改
#define KDataBasePath [NSHomeDirectory() stringByAppendingPathComponent:[NSString stringWithFormat:@"Documents/%@.sqlite", KDataBaseName]] //数据库的路径

@interface XSNSqliteOperation : NSObject

+ (XSNSqliteOperation *)shareOperation;


/**
 创建表
 
 @param tableName 表名
 @param fieldNameModel 存放表字段的数据模型
 @return 是否创建成功
 */
- (BOOL)createTableWithtableName:(NSString *)tableName fieldNameModel:(NSObject *)fieldNameModel;

/**
 根据表名删除表
 
 @param tableName 表名
 @return 是否删除成功
 */
- (BOOL)deleteTableWithtableName:(NSString *)tableName;


/**
 根据表名清空表
 
 @param tableName 表名
 @return 是否删除成功
 */
- (BOOL)cleanTableWithtableName:(NSString *)tableName;

/**
 根据数据模型插入一条数据
 
 @param tableName 表名
 @param model 数据模型
 @param completed 操作结果(YES:成功||NO:失败,错误信息提示)
 */
- (void)insertDataBaseWithtableName:(NSString *)tableName model:(NSObject *)model completed:(void(^)(BOOL isScu,NSString *msg))completed;

/**
 根据数据模型数组插入多条数据
 
 @param tableName 表名
 @param modelArr 数据模型数组
 @param completed 操作结果(失败的对象数组集合)
 */
- (void)insertsDataBaseWithtableName:(NSString *)tableName modelArr:(NSArray *)modelArr completed:(void(^)(NSArray *failArr))completed;

/**
 根据表的一个字段和一个值删除一条数据
 
 @param tableName 表名
 @param fieldName 表的字段名
 @param fieldNameValue 表的字段名所对应的值
 @param completed 操作结果(YES:成功||NO:失败,错误信息提示)
 */
- (void)deleteDataBaseWithtableName:(NSString *)tableName fieldName:(NSString *)fieldName fieldNameValue:(NSString *)fieldNameValue completed:(void(^)(BOOL isScu,NSString *msg))completed;

/**
 根据条件删除多条数据
 
 @param tableName 表名
 @param parameter 键值对查询条件
 @param selectType 键值对查询条件的关系（and \\ or）
 @param completed 操作结果(查询结果,错误信息提示)
 */
- (void)deleteDataBaseWithtableName:(NSString *)tableName byParameter:(NSDictionary *)parameter selectType:(SelectType)selectType completed:(void(^)(BOOL isScu,NSString *msg))completed;

/**
 自己写条件删除
 
 @param tableName 表名
 @param sqlStr 键值对查询条件（例如：name = '张福杰' and sex = '保密'）
 @param completed 操作结果(查询结果,错误信息提示)
 */
- (void)deleteDataBaseWithtableName:(NSString *)tableName sqlStr:(NSString *)sqlStr completed:(void(^)(BOOL isScu,NSString *msg))completed;

/**
 根据表的一个字段更新一条数据
 
 @param tableName 表名
 @param fieldName 表的字段名
 @param model 需要更新的所以字段
 @param completed 操作结果(YES:成功||NO:失败,错误信息提示)
 */
- (void)updateTableWithtableName:(NSString *)tableName fieldName:(NSString *)fieldName model:(NSObject *)model completed:(void(^)(BOOL isScu,NSString *msg))completed;

/**
 根据表的一个字段更新多条数据
 
 @param tableName 表名
 @param fieldName 表的字段名
 @param modelArr 需要更新的所以字段数组
 @param completed 操作结果(更新失败的数组,错误信息提示)
 */
- (void)updateTableWithtableName:(NSString *)tableName fieldName:(NSString *)fieldName modelArr:(NSArray *)modelArr completed:(void(^)(NSArray *failArr,NSString *msg))completed;

/**
 查询表里面的全部数据
 
 @param tableName 表名
 @param completed 操作结果(查询结果,错误信息提示)
 */
- (void)selectAllDataBaseWithtableName:(NSString *)tableName completed:(void(^)(NSArray *resultArr,NSString *msg))completed;

/**
 根据参数条件查询
 
 @param tableName 表名
 @param parameter 键值对查询条件
 @param selectType 键值对查询条件的关系（and \\ or）
 @param completed 操作结果(查询结果,错误信息提示)
 */
- (void)selectAllDataBaseWithtableName:(NSString *)tableName byParameter:(NSDictionary *)parameter selectType:(SelectType)selectType completed:(void(^)(NSArray *resultArr,NSString *msg))completed;

/**
 自己写条件查询语句
 
 @param tableName 表名
 @param sqlStr 条件查询语句（例如：name = '张福杰' and sex = '保密'）
 @param completed 操作结果(查询结果,错误信息提示)
 */
- (void)selectAllDataBaseWithtableName:(NSString *)tableName sqlStr:(NSString *)sqlStr completed:(void(^)(NSArray *resultArr,NSString *msg))completed;


/**
 给表添加新的字段
 
 @param tableName 表名
 @param propertyName 新的字段
 @param completed 操作结果(YES:成功||NO:失败,错误信息提示)
 */
- (void)addNewPropertyWithtableName:(NSString *)tableName propertyName:(NSString *)propertyName completed:(void(^)(BOOL isScu,NSString *msg))completed;

@end
